#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "1c2ce43cef5f4c158e1b7244716eac60";
char ssid[] = "Lake";
char pass[] = "2605782121";
BlynkTimer timer;
int setpoint = -1;
unsigned long lastChange = 0;
const int waitFor = 5000; // 5 secs
const int relayPin = 2;

void updateco2()
{
  double co2 = (analogRead(A0) * 1.284) - 45.234;
  Blynk.virtualWrite(V5, co2);
  Serial.println(analogRead(A0));

  digitalWrite(relayPin, setpoint > co2);
}

BLYNK_WRITE(V1)
{
  setpoint = param.asInt();
  Serial.print("setpoint=");
  Serial.println(setpoint);
}


void setup()
{
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(relayPin, LOW);
    delay(1000);
    digitalWrite(relayPin, HIGH);
    delay(1000);
  }

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, updateco2);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
