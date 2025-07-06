]#include <Servo.h>
const int photoPin=A1; 
const int sensorPin=A5; 
int photoVal; 
Servo myServo; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
myServo.attach(sensorPin); 
}

void loop() {
  // put your main code here, to run repeatedly:
 photoVal = analogRead(photoPin); 
  Serial.println(photoVal); 
  delay(50); 
  if (photoVal>340){ 
    myServo.write(60); 
     Serial.println(photoVal); 
  }
  if (photoVal<330 && photoVal>300){ 
    myServo.write(10); 
    Serial.println(photoVal);
  }
}
