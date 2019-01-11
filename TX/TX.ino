// SimpleTx - the master or the transmitter
//This code analyzes the envriomential data and transmits
//the concern level between temperature, hummidity and smoke. 
//

//Update this on Pi via ssh & vim for github. 
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();


#define CE_PIN   9
#define CSN_PIN 10

const byte slaveAddress[5] = {'R','x','A','A','A'};


RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

char txNum = '0';
const int gasPin = PORTC0;
int dataToSend = 0;
int gasData = analogRead(gasPin);
//float humidityData = sensor.readHumidity();
//float tempData = sensor.readTemperature();
unsigned long currentMillis;
unsigned long prevMillis;
unsigned long txIntervalMillis = 1000; // send once per second


void setup() {

    Serial.begin(9600);

    Serial.println("SimpleTx Starting");

    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setRetries(3,5); // delay, count
    radio.openWritingPipe(slaveAddress);
    //for heat and hummidity detector
    sensor.begin();
}

//====================

void loop() {
    currentMillis = millis();
    if (currentMillis - prevMillis >= txIntervalMillis) {
        send();
        prevMillis = millis();
    }
}

//====================

void send() {

    bool rslt;
    dataToSend = concernLevel();
    rslt = radio.write( &dataToSend, sizeof(dataToSend) );
        // Always use sizeof() as it gives the size as the number of bytes.
        // For example if dataToSend was an int sizeof() would correctly return 2

    Serial.print("Data Sent ");
    Serial.print(dataToSend);
    if (rslt) {
        Serial.println("  Acknowledge received");
    }
    else {
        Serial.println("  Tx failed");
    }
}

//Concern level of 100 means it is a humidity related ~ 80% rh
//Level 200 means it is temperature ~ 35C
//Level 300 means it is humidity and temperature.~ 27C & 70% rh
//Level 500 means it is a smoke/gas concern
//Concern level 0 means we are good.
//Will pirotize sending concerns related to smoke/gas
int concernLevel()
{
  gasData = analogRead(gasPin);
  float humidityData = sensor.readHumidity();
  float tempData = sensor.readTemperature();
 /* Serial.print("Gas concentration:     ");
  Serial.print(gasData);
  Serial.print("\tHumidity:    ");
  Serial.print(humidityData, 2);
  Serial.print("\tTemperature: ");
  Serial.println(tempData, 2);
  */

  if(gasData > 300)
    return 500;
  else if(humidityData > 70 && tempData > 26)
    return 300;
  else if(tempData > 30)
    return 200;
  else if(humidityData > 80)
    return 100;
  else
    return 0;
}
