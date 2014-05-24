Spark Core Weather Monitor using BMP085, DHT22, TSL2561 and Sound Sensor
------------------------------------------------------------------------


A beginner level sample application to monitor weather. The sample uses BMP085, DHT22, TSL2561 and a low cost Sound Sensor.

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

  [1]: https://raw.githubusercontent.com/krvarma/WeatherMon_SparkCore/master/IMG_0064.JPG