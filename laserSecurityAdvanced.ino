//keypad
#include <Keypad.h>
char* pass = "4868#";
const byte ROWS = 4;
const byte COLS = 4;
char Keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
int position = 0;
//now the photoresistor starts
const int photoPin=A5; 
int photoVal; 
const int buzzPin=12; 
const int redPin=13; 
const int greenPin=11; 
bool alarmActive=false; 
bool disArmed=false; 
Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);
 
void resetPass() {
  //this is actually "resetting" the system, the led and buzzer stops 
  digitalWrite(buzzPin,LOW); 
  digitalWrite(redPin,LOW); 
  digitalWrite(greenPin,HIGH); 
  disArmed=true; 
  position=0;  
}

void setup() {
 //add setups here
 pinMode(buzzPin,OUTPUT); 
 pinMode(redPin,OUTPUT); 
 pinMode(greenPin,OUTPUT); 
 Serial.begin(9600); 
}
 
void loop() {
  /*there will be an analogRead here, if statement saying that if the resistor value goes too low, buzzer starts buzzing 
  if the buzzer starts buzzing, and (i think a nested if statement) if the password matches, stop the buzzer from buzzing. 
  else, nothing happens (buzzer is quiet)
  */
  photoVal = analogRead(photoPin); 
  Serial.println(photoVal); 
  //rearms the system
  if (photoVal > 900) {
  disArmed = false;
  position = 0;
}

  if (photoVal<800 && !disArmed){
    alarmActive=true; 
  }
  if (alarmActive){
    digitalWrite(buzzPin,HIGH); 
    digitalWrite(redPin,HIGH); 
    digitalWrite(greenPin,LOW);
    char key = keypad.getKey(); //waiting for the password to be put
  if (key == pass[position]) {
    position ++;
  }
  if (position == 5) {
    resetPass();
    alarmActive=false; 
  }
  delay(100);
   }
   else{ 
    digitalWrite(buzzPin,LOW); 
    digitalWrite(redPin,LOW); 
    digitalWrite(greenPin,HIGH); 
   }
  
}
