// This #include statement was automatically added by the Spark IDE.
#include "SFE_TSL2561.h"

// This #include statement was automatically added by the Spark IDE.
#include "dht.h"
// This #include statement was automatically added by the Spark IDE.
#include "bmp085.h"

#define DHTPIN D4
#define SOUNDPIN A0
#define DHTTYPE DHT22

// Initialize sensor classes
Adafruit_BMP085 bmp;
DHT dht(DHTPIN, DHTTYPE);
SFE_TSL2561 tsl = SFE_TSL2561();

// Initialize variables
char eventinfo[64];
unsigned int ms;
int publishdelay = 60 * 1000;

// Initialize BMP085
void InitializeBMP085(){
    if (!bmp.begin()) {
        Serial.println("Could not find a valid BMP085 sensor, check wiring!");
        while (1) {}
    }
}

// Initialize DHT
void InitializeDHT(){
    dht.begin();
}

// Initialize TSL2561
void InitializeTSL2561(){
    unsigned char id;
    
    tsl.begin();
    
    tsl.getID(id);
    tsl.setTiming(0, 2, ms);
    tsl.setPowerUp();
}

// Initialize Sound Sensor
void InitializeSoundSensor(){
    pinMode(SOUNDPIN, INPUT);
}

// Publish Pressure, Altitude
void PublishBMP085Info(){
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    sprintf(eventinfo, "Pressure=%.2f|hPa,Altitude=%2.2f|meters", bmp.readPressure()/100.0, bmp.readAltitude());
    
    Serial.println();
    
    Publish(eventinfo);
}

// Publish Temperature, Humidity, Dew Point
void PublishDHTInfo(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float d = dht.dewPoint(t, h);

    sprintf(eventinfo, "Temperature=%.2f|°C,Humidity=%.2f|%%,Dew Point=%.2f|°C", t, h, d);
    
    Publish(eventinfo);
}

// Publish  luminosity
void PublishTSL2561Info(){
    unsigned int data1;
    unsigned int data2;
    boolean gain;

    tsl.getData(data1, data2);
    
    double lux;
    boolean good = tsl.getLux(gain,ms,data1,data2,lux);
    
    sprintf(eventinfo, "Lux=%.2f|Lux", lux);
    
    Publish(eventinfo);
}

// Publish sound info
void PublishSoundInfo(){
    // map analog reading (0-4095) to (0-100)
    int level = map(analogRead(SOUNDPIN), 0, 4095, 0, 100);
    
    // Just some arbitrary values
    if(level > 60){
        sprintf(eventinfo, "Sound Level=%d (High)|", level);
    }
    else if(level > 30){
        sprintf(eventinfo, "Sound Level=%d (Medium)|", level);
    }
    else{
        sprintf(eventinfo, "Sound Level=%d (Low)|", level);
    }
    
    Publish(eventinfo);
}

// Publush event
void Publish(char* szEventInfo){
    Spark.publish("weatherinfo", szEventInfo);
}

// Initialize applicaiton
void InitializeApplication(){
    Serial.begin(9600);
    pinMode(D7, OUTPUT);
}

// Blink LED and wait for some time
void BlinkLED(){
    digitalWrite(D7, HIGH);   
    delay(500);
    digitalWrite(D7, LOW);   
    delay(500);
    
    delay(publishdelay);
}
  
void setup() {
    InitializeApplication();
    
    Serial.println("Initializing sensors...");
    
    InitializeBMP085();
    InitializeDHT();
    InitializeTSL2561();
    InitializeSoundSensor();
}
  
void loop() {
    // Publish events. Wait for 2 second between publishes
    PublishBMP085Info(); 
    delay(2000);
    PublishDHTInfo(); 
    delay(2000);
    PublishTSL2561Info(); 
    delay(2000);
    PublishSoundInfo();
    delay(2000);
    
    BlinkLED();   
}