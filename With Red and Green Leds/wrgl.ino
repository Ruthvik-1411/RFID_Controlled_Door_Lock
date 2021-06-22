// Including Libraries

#include<Servo.h>                                        //Include servo.h library for functions such as attach,write etc.
#include<SPI.h>                                          //Include Serial Peripheral Interface (SPI.h) library for communication with one or more peripheral devices.
#include<MFRC522.h>                                      //Include MFRC522.h library for the RFID-RC522 Module and functions to read data.                          

#define SS_PIN 10                                       // Defining SS(SDA) pin as 10.
#define RST_PIN 9                                       // Defining RST pin as 9.
#define Rled 5                                          // Defining the Red and Green Led pins. 
#define Gled 6
#define servopin 7                                      // Defining Servo pin at 7.

int anglei=15;                                         // Initialising initial angle of servo to 15deg.
int anglef=90;                                         // Initialising final angle of servo to 90deg.
int A_delay = 5000;                                    // Declaring the Access delay to be 5 seconds 
int D_delay = 2000;                                    // Declaring the Denied delay to be 2 seconds.
String card_status;                                    // Declaring two strings, card status and user name.
String user;

Servo myservo;                                        // Instance of servo as myservo
MFRC522 my_mfrc522(SS_PIN, RST_PIN);                  //Instance of MFRC522 as my_mfrc522 with SS pin, RST pin as arguments

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                                   // Initiate a Serial communication
SPI.begin();                                          // Initiate SPI bus
my_mfrc522.PCD_Init();                                // Initiate MFRC522
pinMode(servopin, OUTPUT);                            // Declaring servopin,Red led and green leds as Outputs
pinMode(Rled,OUTPUT);
pinMode(Gled,OUTPUT);
myservo.attach(servopin);                                    // Telling servo is attached at 7
myservo.write(anglei);                                       // Writing servo to be at initial angle i.e. 15deg.
delay(10);                                                   // wait for 10 micro seconds.
my_mfrc522.PCD_DumpVersionToSerial();                       // Get the version of RFID module and print in serial monitor
Serial.println("Put Your card to Access...");
Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!my_mfrc522.PICC_IsNewCardPresent()){                        //Look for new cards and if not found return back
    return;
  }
 if(!my_mfrc522.PICC_ReadCardSerial()){                          //Read the Card serial number if present and if unable to read return back
  return;
 }
Serial.print("UID tag :");                                       // Show UID on serial monitor
String ID;                                                       // Initialise a String with name ID
byte letters;                                                    // Initialise a byte with name letters
for(byte i=0;i<my_mfrc522.uid.size;i++){                         // Reading the data from the scanning proccess and from the RFID.
  Serial.print(my_mfrc522.uid.uidByte[i]<0x10 ? "0" : " ");
  Serial.print(my_mfrc522.uid.uidByte[i],HEX);
  ID.concat(String(my_mfrc522.uid.uidByte[i]<0x10 ? "0" : " "));
  ID.concat(String(my_mfrc522.uid.uidByte[i],HEX));
}
Serial.println();
ID.toUpperCase();                                                // Convert the string into all upper case 
if (ID.substring(1) == "FA BC 4E B4" ){                          // Check if the UID of the card is in the list of cards having access
 card_status="Access granted";                                   // If yes then grant access to the specific user
 user = "Ruthvik";
}
else if (ID.substring(1) == "7A FF 18 3F"){  // substring = if the string contains this specific string
card_status="Access granted";
user = "Sugreev";
}
else                                                            // If the UID of the card is not in the list of cards with access then access is denied
{ 
  card_status="Access denied";
}

  if(card_status == "Access granted" ){
    Serial.print("Hello ");                                     // Print Hello "user" and ON the Green Led
    Serial.println(user);
    digitalWrite(Gled,HIGH);
    myservo.write(anglef);                                     // write the servo to move to final angle i.e. 90deg.
    delay(A_delay);                                            // wait for access delay i.e. 5 seconds.
    digitalWrite(Gled,LOW);                                   // OFF the Led and write the servo back to initial angle.
    delay(1000);
    myservo.write(anglei);
    Serial.println();
  }
  else if(card_status == "Access denied"){
    Serial.println("Sorry, seems like you have no access..."); 
    myservo.write(anglei);                                  // Keep the servo at the initial angle and ON the red led
    digitalWrite(Rled,HIGH);
    delay(D_delay);                                        // wait for denied delay i.e. 2 seconds and OFF the red led
    digitalWrite(Rled,LOW);
  }
delay(2000);
}
