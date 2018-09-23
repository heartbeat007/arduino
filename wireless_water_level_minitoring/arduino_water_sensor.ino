#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX
const int waterSens = A0; //define water sensor
//const int led = 9;//define led to pin 9
int waterVal; //define the water sensor value
void setup() {
  // put your setup code here, to run once:

//pinMode(led, OUTPUT); //set led as an output
pinMode(waterSens, INPUT);//set water sensor as an input
BTserial.begin(9600); 
Serial.begin(9600);  //start the serial port at 9600 bauds

}

void loop() {
  // put your main code here, to run repeatedly:
waterVal = analogRead(waterSens); //read the water sensor
Serial.println(waterVal); //print the value of the water sensor to the serial monitor
BTserial.print(waterVal);
BTserial.print(";");
if(waterVal>240){
BTserial.print("danger");
BTserial.print(";");
}

delay(100); 
}
