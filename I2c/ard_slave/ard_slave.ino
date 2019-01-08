// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
  int i;
  float val[5] = {3.1,3.2,3.3,3.4,3.5};
  char buff[10];
  char valueString[100] = "";
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
   for (i = 0; i < 5; i++) {
    float val1 = val[i];
    dtostrf(val1, 4, 2, buff);  //4 is mininum width, 6 is precision
    Serial.print("val: ");
    Serial.println(val1);
    Serial.print("buff: ");
    Serial.println(buff);
     
    strcat(valueString, buff);
	strcat(valueString, ";");
 
  }
  Serial.println(valueString);
  
  
  Wire.write(valueString); // respond with message of 6 bytes
  // as expected by master

}
