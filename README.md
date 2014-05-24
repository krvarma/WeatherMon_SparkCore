Spark Core Weather Monitor using BMP085, DHT22, TSL2561 and Sound Sensor
------------------------------------------------------------------------

A beginner level sample application to monitor weather. The sample uses BMP085, DHT22, TSL2561 and a low cost Sound Sensor.A sample application to monitor weather conditions. The application reports Temperature, Humidity, Altitude, Dew Point, Luminosity and Sound Level and uses BMP085. DHT22, TSL2561 and a low cost Sound Sensor. The application publishes events in every 1 minute.

###Wiring###
 1. TSL2561 Vcc to 3.3V
 2. TSL2561 GND to GND 
 3. TSL2561 SCL to D1
 4. TSL2561 SDA to D0
 5. BMP085 Vcc to 3.3V
 6. BMP085 GND to GND 
 7. BMP085 SCL to D1
 8. BMP085 SDA to D0
 9. DHT22 Vcc to 3.3V
 10. DHT22 GND to GND
 11. DHT22 Signal to D4
 12. Sound Sensor Vcc to 3.3V
 13. Sound Sensor GND to GND
 14. Sound Sensor Signal to A0
 
![enter image description here][1]

 
###How to run the application###
Load the sample application into the Spark Core. Open the ***weathermon.html***, enter Core ID, Access Token, Event Name and press *Subscribe to Events* button.

There are two separate modules in this sample, Spark Core application and HTML page to view the published events. The Spark Core application publishes events in the form *sensor name=sensor value|unit*. The HTML page uses JavaScript to parse the event data and display values from the sensor. The HTML page first asks Core ID and Access Token and uses this to subscribe to the events.

**Screenshots**

*Initial page asking Core ID and Access Token*
![enter image description here][2]

*Sensor display*
![enter image description here][3]


  [1]: https://raw.githubusercontent.com/krvarma/WeatherMon_SparkCore/master/IMG_0064.JPG
  [2]: https://raw.githubusercontent.com/krvarma/WeatherMon_SparkCore/master/coreid.png
  [3]: https://raw.githubusercontent.com/krvarma/WeatherMon_SparkCore/master/weather.png