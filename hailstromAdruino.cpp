//#include <Boards.h>
//#include <Firmata.h>
//#include <FirmataConstants.h>
//#include <FirmataDefines.h>
//#include <FirmataMarshaller.h>
//#include <FirmataParser.h>

#include <AFMotor.h>  
#include <NewPing.h>
//#include <Servo.h>
AF_DCMotor motor(4);
int threshold=200;
void checksensor(){
  while(1>0)
  {
    int value = analogRead(A1);
    Serial.println(value);
    delay(1000);
    if(value>threshold)
    {
      motor.setSpeed(200);
      delay(100);
      motor.run(FORWARD);
      delay(5000);
      motor.run(RELEASE);
      break;
    }}}
void backwardsetup(){
  int value = analogRead(A1);
    Serial.println(value);
    delay(1000);
    if(value>threshold)
    {
      motor.setSpeed(200);
      delay(100);
      motor.run(BACKWARD);
      delay(5000);
      motor.run(RELEASE);
}}
void setup() {
  Serial.begin(9600);
//  pinMode(3,OUTPUT);
  pinMode(A0,INPUT);
  checksensor(); }

void loop() 
{
  int value = analogRead(A1);
  Serial.println(value); 
  int t=0;
  while(value<threshold)
  {
    t+=1;
    if(t>=10)
    {
      backwardsetup();
    }}}
