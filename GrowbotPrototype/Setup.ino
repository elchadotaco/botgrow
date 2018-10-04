void setup()
{
  WiFiManager wifiManager;
  Serial.begin(74880);

  Serial.println("Connecting to network...");
  String ssid = "GrowBot-" + String(ESP.getChipId());
  wifiManager.autoConnect(ssid.c_str());

  Serial.println("Contacting blynk...");
  
  Blynk.config(auth);
  Blynk.connect();

  // Pins
  pinMode(RELAY_PIN, OUTPUT);

  timer.setInterval(1000L, updateco2);
  Serial.println("Done.");
}

