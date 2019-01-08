  int i;
  float val[5] = {3.1,3.2,3.3,3.4,3.5};
  char buff[10];
  char valueString[100] = "";
  int sensors[5] = {1,2,3,4,5}; 


void setup()
{

  Serial.begin(9600);
  val = {3.1,3.2,3.3,3.4,3.5};
  for (i = 0; i < 5; i++) {
    float val1 = val[i];
    dtostrf(val1, 4, 2, buff);  //4 is mininum width, 6 is precision
    Serial.print("val: ");
    Serial.println(val1);
    Serial.print("buff: ");
    Serial.println(buff);
     
    strcat(valueString, buff);
	strcat(valueString, ", ");
 
  }
  Serial.println(valueString);
}

void loop() {
}	
