//Libraries
#include <Adafruit_AHTX0.h>
#include <Arduino_MKRGPS.h>
#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_AHTX0 aht; //initialise sensor
float UVVoltage; 
float UVValue;
float latitude   = GPS.latitude();
float longitude  = GPS.longitude();
float altitude   = GPS.altitude();
float speed      = GPS.speed();
int   satellites = GPS.satellites();
void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 or AHT20 found");
   if (!GPS.begin()) {
    Serial.println("Failed to initialize GPS!");
    while (1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Serial.print("Sending packet: ");
    if (GPS.available()) {
    // read GPS values
    float latitude   = GPS.latitude();
    float longitude  = GPS.longitude();
    float altitude   = GPS.altitude();
    float speed      = GPS.speed();
    int   satellites = GPS.satellites();
    }
    //UV sensor
    UVValue = analogRead(A1);
    UVVoltage = UVValue/1024*5.0;
    //Printing all the data
    //AHT10
    Serial.println("temperature: ");
    Serial.print(temp.temperature);
    Serial.println("humidity: ");
    Serial.print(humidity.relative_humidity);
    //GPS
    Serial.print("Location: ");
    Serial.print(latitude, 7);
    Serial.print(", ");
    Serial.println(longitude, 7);

    Serial.print("Altitude G: ");
    Serial.print(altitude);
    Serial.println("m");

    Serial.print("Ground speed: ");
    Serial.print(speed);
    Serial.println(" km/h");

    Serial.print("Number of satellites: ");
    Serial.println(satellites);
    Serial.println("UV Voltage: ");
    Serial.print(UVVoltage);
    Serial.println("UV Index: ");
    switch (UVVoltage){
     case (UVVoltage < 50):
      Serial.print("0");
      break;
     case (UVVoltage >= 50 && UVVoltage < 227):
      Serial.print("1");
      break;
     
      
    }

}
