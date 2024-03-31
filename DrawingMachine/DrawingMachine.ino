#include <Stepper.h>
#include <Servo.h>
// DECLARARE MOTORASE
Servo myservo;
Stepper ox(2048,8,10,9,11);
Stepper oy(2048,4,6,5,7);

int angle=2;            //UNGHIUL DE ROTATIE PT servomotor:= RIDICA/COBOARA CEIONUL PE FOAIE
int motorSpeed=10;      //VITEZA DE ROTATIE A stepmotoarelor
int i=0;
unsigned long previousMillis = 0;
const int interval = 100;  // intervalul dorit în milisecunde

void setup() {
  //servo
  Serial .begin(9600);
  myservo.attach(3);        
  myservo.write(-angle);      //SE COBOARA CREIONUL PE FOAIE
  ox.setSpeed(motorSpeed);    //setam viteza la motorase
  oy.setSpeed(motorSpeed);
}

void loop() {
  //DESENARE PATRAT
  //miscareOZ(-angle);
  miscareOX(6,2048);
  miscareOY(8,-2048);
  miscareOX(6,-2048);
  miscare(8,2048);
}

void miscareOX(int repetitii, int rotatie){    //rotatie = 2048 => ROTATIE COMPLETA
  unsigned long currentMillis = millis();
  for(i=0;i<repetitii;i++){
    ox.step(rotatie);            
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // salvează timpul curent
    }                               
  }
}

void miscareOY(int repetitii, int rotatie){
  unsigned long currentMillis = millis();
  for(int i=0;i<repetitii;i++){
    oy.step(rotatie);            
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;  // salvează timpul curent
    }
  }
}

void miscareOZ(int rotateWithAngle){
  myservo.write(rotateWithAngle);
}