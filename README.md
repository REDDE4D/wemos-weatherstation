
## Wemos Weather Station
This is a simple Arduino script for monitoring temperatur, humidity, pressure and battery level
with a Wemos D1 mini and a BME280 over MQTT to HomeAssistant (or any other Smarthome Hub).
Running up to 14 Days on a single charge. (depending on sending interval default every 30mins)
Gerber files for pcb included.

### Used Libraries
- cactus_io_BME280_I2C
- ESP8266WiFi
- MQTT

### Requirements
- Wemos D1 mini - https://www.amazon.de/AZDelivery-D1-Mini-Entwicklungsboard-kompatibel/dp/B01N9RXGHY/
- BME280 - https://www.amazon.de/Breakout-Temperatur-Feuchtigkeitssensor-Hochgenaues-digitales-Luftdrucksensormodul/dp/B08H22BX5M/
- 18650 Battery holder - https://www.amazon.de/gp/product/B081HW4TGR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
- 18650 Battery - https://www.amazon.de/Sung-18650-35E-3450mAh-Akku-Einsatzm%C3%B6glichkeiten/dp/B0811P458W/
- JST PH 2.0 - https://www.amazon.de/gp/product/B07449V33P/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1
- 180k Ohm resistor - https://www.amazon.de/Widerstand-St%C3%BCck-Metallschicht-Metallfilm-Widerst%C3%A4nde/dp/B00I9YYFIW/
- 2pin Jumper - https://www.amazon.de/gp/product/B086MZN5JQ/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1

### Shematic
![shema](https://user-images.githubusercontent.com/12301042/124390537-5ddba380-dcec-11eb-8d0f-03f816cc26a4.png)
