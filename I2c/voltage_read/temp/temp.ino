
int i = 0;
const int numReadings = 200;

float readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float  total = 0;                  // the running total
float  average = 0;                // the average
float voltages[4];
char in_signal = '0';

int l;
char buff[10];
char valueString[100] = "";




void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
  readings[thisReading] = 0;}
}

// the loop function runs over and over again forever
void loop() {

  if (Serial.available() > 0) {
     // read the incoming byte:
     in_signal = Serial.read();
     if(in_signal == '1'){

      for(i=2 ; i <=5; i++){

         digitalWrite(i, LOW);
         float inp_voltage = analogRead(A0) ;
         float voltage = inp_voltage * (4.40 / 1023.0);
         int readingq = numReadings  ;

          while(  readingq != 0){

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

          readingq--  ;
        }
    int j = i-1;
    voltages[j-1] = average;
    delay(200);
    digitalWrite(i, HIGH);


   }

      for(int k = 0; k < 4; k++)
    {
      Serial.print(voltages[k]);
      Serial.write(char(voltages[k]));
      Serial.print("\t");
      Serial.print("\n");
      
      float val1 = voltages[k];
      dtostrf(val1, 4, 2, buff);  //4 is mininum width, 6 is precision
      //Serial.print("val: ");
      //Serial.println(val1);
      //Serial.print("buff: ");
      //Serial.println(buff);
     
      strcat(valueString, buff);
      strcat(valueString, ";");
 
    }
    Serial.println(valueString);
  
       }
    }
}
