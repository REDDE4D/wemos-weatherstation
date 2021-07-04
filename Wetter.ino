#include <MQTT.h>
#include <MQTTClient.h>
#include "cactus_io_BME280_I2C.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "settings.h"
#include "topics.h"


BME280_I2C bme(0x76);
WiFiClient net;
MQTTClient mqtt;

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
  Serial.println();
  int battVoltage = analogRead(A0);
  Serial.println("Booting...");
  Serial.println();
  Serial.println("Checking for BME280...");
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  while (1);
  }
  else {
    Serial.println("BME280 sensor found, continue booting!");
  }
 
  Serial.println();
  Serial.println("Starting Setup...");
 
  connect();
  
  Serial.println("Setup completed!");

  mqtt.loop();

  Serial.println();
  Serial.println("Reading sensor data...");
  bme.setTempCal(-1);// Temp was reading high so subtract 1 degree
  bme.readSensor();
  float hu = bme.getHumidity();
  float te = bme.getTemperature_C();
  float pr = bme.getPressure_HP();

  Serial.print("Sending data... ");
  mqtt.publish(lwt, "online");
  mqtt.publish(temperatur, String(te));
  mqtt.publish(humidity, String(hu));
  mqtt.publish(pressure, String(pr));
  mqtt.publish(vcc, String(battVoltage));

  mqtt.disconnect();

  Serial.println("Going into deep sleep for 30 minutes");
  ESP.deepSleep(1800 * 1000000); // z.b. 20e6 sind 20 sekunden

}

void connect() {
  WiFi.mode(WIFI_AP_STA);
  while(WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(wifi_ssid, wifi_password);
    WiFi.hostname(wifi_clientname);
    delay(500);
    Serial.println("WiFi connection failed. Retry.");
  }
 
  Serial.print("Wifi: connection successful - IP-Address: ");
  Serial.println(WiFi.localIP());
 
  mqtt.begin(mqtt_host, net);
  while (!mqtt.connect(mqtt_host, mqtt_user, mqtt_pwd)) {
    Serial.print("*");
  }
  Serial.println("MQTT: connected!");
  delay(500);
}

void loop() {
  
}
