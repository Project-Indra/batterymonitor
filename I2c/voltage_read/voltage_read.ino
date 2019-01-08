
const int numReadings = 200;

float readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float  total = 0;                  // the running total
float  average = 0;                // the average


void setup() {
  Serial.begin(9600);
   for (int thisReading = 0; thisReading < numReadings; thisReading++) {
   readings[thisReading] = 0;}
}

void loop() {
  float  inp_voltage = analogRead(A0)*2 ;
  float voltage = inp_voltage * (4.40 / 1023.0);
  //Serial.println(y);
 // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = voltage;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.println(average);
        // delay in between reads for stability
}
