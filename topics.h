String topic_1 = "/LWT";
String topic_2 = "/data/Temperatur";
String topic_3 = "/data/Humidity";
String topic_4 = "/data/Pressure";
String topic_5 = "/data/VCC";

String topic_lwt = device_name + topic_1;
String topic_temperatur = device_name + topic_2;
String topic_humidity = device_name + topic_3;
String topic_pressure = device_name + topic_4;
String topic_vcc = device_name + topic_5;

const char * lwt = topic_lwt.c_str();
const char * temperatur = topic_temperatur.c_str();
const char * humidity = topic_humidity.c_str();
const char * pressure = topic_pressure.c_str();
const char * vcc = topic_vcc.c_str();
