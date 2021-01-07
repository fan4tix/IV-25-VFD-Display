/*
Example use case of the system as a wireless IOT display.
https://api.someservice.com/data.json needs to have the following format:

{
  "text" : ["line1", "line2", "line3", ...]
}

The code will download and parse the JSON-file and display
each line sequentially.

Note: This is not necessarily a secure implementation.
Do not use in a production environment.
*/

#include "display.h"
#include "iv25_font.h"
#include "limits.h"
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h> // Include the Wi-Fi library
#include <WiFiClientSecureBearSSL.h>

const char *ssid =
    "YOUR SSID HERE"; // The SSID (name) of the Wi-Fi network you want to connect to
const char *password =
    "YOUR PASSWORD HERE"; // The password of the Wi-Fi network
const char *api_server = "https://api.someservice.com";
const char *api_uri = "/data.json";
const long update_interval = 8L;

unsigned long last_update;
HTTPClient http;
#define NUM_TUBES (6 * 8)
#define MAX_LINE_LENGTH 1024

int latchPin = 13;  // Pin connected to ST_CP of 74HC595
int clockPin = 16;  // Pin connected to SH_CP of 74HC595
int dataPin = 14;   // Pin connected to DS of 74HC595
int enablePin = 12; // Pin connected to the Cathode MOSFET

IV25Display dsp(NUM_TUBES, latchPin, dataPin, clockPin, enablePin);

unsigned long last_check = 0;

char str[MAX_LINE_LENGTH];

uint16_t buflen = 1024 * 6;
uint8_t *buf = (uint8_t *)calloc(
    buflen, sizeof(uint8_t)); // Create buffer with one byte for each

DynamicJsonDocument doc(2 * MAX_LINE_LENGTH);

JsonArray lines;
void setup() {
  Serial.begin(115200); // Start the Serial communication to send messages to
                        // the computer
  delay(10);
  Serial.println('\n');

  buflen *= sizeof(char);

  WiFi.begin(ssid, password); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" ...");
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(
      WiFi.localIP()); // Send the IP address of the ESP8266 to the computer

  last_update = millis();
  get_lines(&doc);
  lines = doc["text"].as<JsonArray>();
}

void loop() {
  if (millis() - last_update > (update_interval * 1000)) {
    last_update = millis();
    get_lines(&doc);
    lines = doc["text"].as<JsonArray>();
  }
  for (JsonVariant line : lines) {
    Serial.println(line.as<char *>());
    strncpy(str, line.as<char *>(), MAX_LINE_LENGTH);
    dsp.print(str);
    while (!dsp.fully_scrolled()) {
      dsp.scroll();
      delay(200);
    }
    delay(2000);
  }
}

void get_lines(DynamicJsonDocument *doc) {

  Serial.println("Connecting to the HTTP server....");
  std::unique_ptr<BearSSL::WiFiClientSecure> client(
      new BearSSL::WiFiClientSecure);
  client->setInsecure();
  char apiURL[1024];
  Serial.println("Building URL...");
  sprintf(apiURL, "%s%s", api_server, api_uri);

  Serial.printf("API URL=%s\r\n", apiURL);
  if (http.begin(*client, apiURL)) {
    Serial.println("Connected");
    http.addHeader("Accept", "application/json");
    //  http.addHeader("apikey", API_KEY);
    int code = http.GET();
    Serial.printf("HTTP Code [%d]", code);
    if (code > 0) {
      if (code == HTTP_CODE_OK || code == HTTP_CODE_MOVED_PERMANENTLY) {
        Serial.println("GET OK");
        String payload = http.getString();
        Serial.println(payload);

        deserializeJson(*doc, payload.c_str());
        Serial.println("...JSON..");
      }
    } else {
      Serial.printf("[HTTP] GET... failed, error: %s",
                    http.errorToString(code).c_str());
    }
  }
}
