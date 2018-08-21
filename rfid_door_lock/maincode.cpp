//first include the library
#include <SPI.h> //for serial communication
#include <MFRC522.h>  //for the rfid 
#include <Servo.h>  //controlling servo motor
// now define some pin
#define SS_PIN 10
#define RST_PIN 19
#define LED_G 4 //define the green led
#define LED_R 5   //define the red led
#define BUZZER 2  // define the buzzer pin
// create a MFRC522 instance or we called it object
MFRC522 mfrc522(SS_PIN,RST_PIN);
//now create a servo instance
Servo myServo ;//creating a Servo object
void setup() {
  // put your setup code here, to run once:
  //this code will run only once
  //start the serial monitor
  Serial.begin(9600);
  SPI.begin(); //begin the spi connection
  mfrc522.PCD_Init();  //start the MFRC522
  myServo.attach(2);    //attach the servo with the pin
  //take the servo to the initial position
  //myServo.write(0);
  //set the pin mode of the led and the buzzer
  pinMode(LED_G,OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  //set to no tone 
  noTone(BUZZER);
  //prompt the user to enter the card
  Serial.println("put your card in the reader ...");
  Serial.println();
  

}

void loop() {
  // put your main code here, to run repeatedly:


  //search for new cards
  if( ! mfrc522.PICC_IsNewCardPresent()){
      return;
    }

    //select one of the card
  if ( ! mfrc522.PICC_ReadCardSerial()){
    return;
  }

  //Show UID on the serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();


//now we got the code lets match the code

if(content.substring(1)== "27 F4 CC 06"){
  
  Serial.println("Authorised Access");
  Serial.println();
  delay(500);
  //start the green led
  digitalWrite(LED_G,HIGH);
  //start the buzzer
  tone(BUZZER,5000);
  delay(300);
  noTone(BUZZER);
  //spin the servo
  myServo.write(180);
  //delay(5000);
  //myServo.write(0);//back to the initial position
  digitalWrite(LED_G,LOW);
  }
  else {
    
    Serial.println("Access Denied");
    digitalWrite(LED_R,HIGH);
    tone(BUZZER,3000);
    delay(1000);
    digitalWrite(LED_R,LOW);
    noTone(BUZZER);
    }





  
}



