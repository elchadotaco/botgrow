#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>

char auth[] = "1c2ce43cef5f4c158e1b7244716eac60";

BlynkTimer timer;
int setpoint = -1;

// Settings
const int CO2_PIN = A0;
const int RELAY_PIN = D1;

// Blynk functions
BLYNK_WRITE(V1)
{
  setpoint = param.asInt();
  Serial.print("setpoint=");
  Serial.println(setpoint);
}
