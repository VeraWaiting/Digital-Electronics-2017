
void setup() 
{ 
  Serial.begin(9600);
} 

 
void loop() 
{
  //sent value of analog input:
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.print(analogRead(A1));
  Serial.print(",");
  Serial.print(analogRead(A2));
  Serial.print(",");
  Serial.print(analogRead(A3));
  Serial.print(",");
  Serial.print(analogRead(A4));
  Serial.print(",");
  Serial.println(analogRead(A5));  
  
  delay(2);

}
