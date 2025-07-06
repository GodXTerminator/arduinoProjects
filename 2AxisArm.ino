#include <Servo.h>
#include <Stepper.h>
int stepsPerRevolution=2048; 
int motSpeed=10; 
int servoPin= 3; 
int xPin=A1; 
int yPin=A0; 
int xVal; 
int yVal;
int deadZone=10; 
float angle; 
float steps; 
Servo myServo; 
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); 

void setup() {
  // put your setup code here, to run once:
pinMode(servoPin,OUTPUT); 
myServo.attach(servoPin); 
pinMode(yPin,INPUT); 
pinMode(xPin,INPUT); 
Serial.begin(9600); 
myStepper.setSpeed(motSpeed); 
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal=analogRead(xPin); 
  yVal=analogRead(yPin); 
Serial.print(xVal);  
Serial.print(" ");
Serial.println(yVal);
if (yVal<520){ 
  angle=((-9./49.)*yVal)+(9090./49.);
  myServo.write(angle); 
}
if (yVal>520){ 
  angle=((-9./52.)*yVal) +180; 
  myServo.write(angle); 
}
if (xVal>(485-deadZone)){ 
  myStepper.step(10); 
}
if (xVal<(485+deadZone)){ 
  
  myStepper.step(-10); 
}
}
