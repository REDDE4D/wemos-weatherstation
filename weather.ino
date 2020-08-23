#include <ESP8266HTTPClient.h>

#include <Wire.h>
#include "cactus_io_BME280_I2C.h"
#include <ESP8266WiFi.h>

// BME280_I2C bme; // I2C using address 0x77
BME280_I2C bme(0x76); // I2C using address 0x76

const char* ssid     = "xxx"; //Wifi-Name
const char* password = "xxx"; //Wifi-Password

String stationName = "xxx";
String apiPath = "http://serveradress/path/to/save.php";

void setup() {

  Serial.begin(9600);
  delay(10);
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting...");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while(WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP Address:");
  Serial.println(WiFi.localIP());
   
  if (!bme.begin()) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  while (1);
  }
  
  bme.setTempCal(-1);// Temp was reading high so subtract 1 degree
  bme.readSensor();
  float hu = bme.getHumidity();
  float te = bme.getTemperature_C();
  float pr = bme.getPressure_HP();

  int h = round(hu);
  int t = round(te);
  int p = round(pr);


  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
  
    String apiRequestPath = apiPath + "?station=" + stationName + "&temp=" + t + "&humid=" + h + "&press=" + p;
    Serial.print("Requesting: ");
    Serial.println(apiRequestPath);
    
    http.begin(apiRequestPath.c_str());
  
    // Send HTTP GET request
    int httpResponseCode = http.GET();
  
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.print("Answer: ");
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }

 ESP.deepSleep(1200e6); //Arduino DeepSleep (20Min)

}


void loop() {
  
}
