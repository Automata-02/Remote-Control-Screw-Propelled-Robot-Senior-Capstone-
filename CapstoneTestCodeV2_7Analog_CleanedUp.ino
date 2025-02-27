//initially written on 4.6.2022 by Ed Cifune
#include <SoftwareSerial.h> //Serial Library
#include<Sabertooth.h>  //Sabertooth Library

//dip switches set to new: 1up 2up 3down 4down 5down 6down  old:(1up 2down 3up 4down 5up 6up)
//For control with the left stick of the controller 
#define LHstick_FR 3 //for forward and backward throttle (reciever channel 3)
#define LHstick_LR 2 //for moving forward with a turn left or right (reciever channel 4)
#define RHstick_LR 4 //for strafing left or right (channel 1)
//ENA and ENB pins are the 2 signal output pins to the front sabertooth
#define ENA_PIN 9   //these pins are indeed the motor output pins 
#define ENB_PIN 10   //  replace ENA and ENB pins with motor output pins
//back half
#define ENC_PIN 11
#define END_PIN 12

//this helps check if our rc controller is connected to the reciever
double channel1;
double channel3;
double channel4;

void setup() {
  //might need to use: ST.autobaud(); or SerialPort.begin(9600);
  Serial.begin(9600); //baud rate 
  
  //radio reciever input pins/channels
  pinMode(LHstick_FR, INPUT);
  pinMode(LHstick_LR, INPUT);
  pinMode(RHstick_LR, INPUT);
  //pinMode(led, OUTPUT);//for reciever testing delete later
  
  //Sabertooth 1 motor control signals output
  pinMode(ENA_PIN, OUTPUT);    
  pinMode(ENB_PIN, OUTPUT);   
  pinMode(ENC_PIN, OUTPUT); 
  pinMode(END_PIN, OUTPUT);    
  //digitalWrite(ENA_PIN, LOW);   //Turn off all the speed and direction pins
  //digitalWrite(ENB_PIN, LOW);   //so the states are known and not moving 

}

void loop() {
  //check/read pulses from reciever
  //multiple channels corresponding to each channel sending information from the reciever
  channel1 = pulseIn(RHstick_LR,HIGH);
  channel3 = pulseIn(LHstick_FR,HIGH);//, 25000); //forward reverse input
  channel4 = pulseIn(LHstick_LR,HIGH);//, 25000);
  Serial.println("_______________________________________________ ");
  Serial.print("Ch1: ");
  Serial.println(channel1);
  Serial.print("Ch3: ");
  Serial.println(channel3);
  Serial.print("Ch4: ");
  Serial.println(channel4);


 int M = map(channel3,1685,1059,0,255); //
 if (M<0) {
   M=0;
 } else if (M>255) {
   M=255;
 }
Serial.print("M: ");
Serial.println(M); 

int LR = map(channel4,1815,950,0,255); //
if (LR<0) {
   LR=0;
 } else if (LR>255) {
   LR=255;
 }
Serial.print("LR: ");
Serial.println(LR);


int SLR = map(channel1,2079,1206,0,255); //
if (SLR<0) {
   SLR=0;
 } else if (SLR>255) {
   SLR=255;
 }
Serial.print("SLR: ");
Serial.println(SLR);


//if statement to control forward/backward movement
if (M>158 || M < 98){
//analogue pin output testing
//you can analogwrite to digital pins if necessary
analogWrite(ENA_PIN,M); 
analogWrite(ENB_PIN,M);
analogWrite(ENC_PIN,M);
analogWrite(END_PIN,M);
}
else if (LR>158){ //if statement to control forward movement with a turn
analogWrite(ENA_PIN, 128);
analogWrite(ENB_PIN, LR);
analogWrite(ENC_PIN, 128);
analogWrite(END_PIN, LR);
}
else if (LR<98){
analogWrite(ENA_PIN, LR);
analogWrite(ENB_PIN, 128);
analogWrite(ENC_PIN, LR);
analogWrite(END_PIN, 128);

}
else if (SLR>158 || SLR< 98){ //if statement to control strafing movement
analogWrite(ENA_PIN, SLR);
analogWrite(ENB_PIN, -SLR);
analogWrite(ENC_PIN, SLR);
analogWrite(END_PIN, -SLR);
}
else {
analogWrite(ENA_PIN,128);
analogWrite(ENB_PIN,128);
analogWrite(ENC_PIN,128);
analogWrite(END_PIN,128);
}
 
  
}
