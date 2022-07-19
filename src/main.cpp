#include <Arduino.h>
#include "Arduino_LSM9DS1.h"

int timestamp = 0;
float x, y, z;
unsigned long previous_time = 0;
unsigned long base_time = 10;  
void setup() {
  
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("timestamp,accX,accY,accZ");
}

void loop() {

  if(millis() >= previous_time+base_time){
    previous_time = millis();
    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(x, y, z);
    }
    Serial.println(String(timestamp)+","+String(x)+","+String(y)+","+String(z));
    timestamp++;
  }
}