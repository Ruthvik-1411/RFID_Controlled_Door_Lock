// Including Libraries

#include<Servo.h>                                     //Include servo.h library for functions such as attach,write etc.
#include<LiquidCrystal.h>                             //Include Liquid Crystal.h library for functions such as print, clear etc on LCD. 
#include<SPI.h>                                       //Include Serial Peripheral Interface (SPI.h) library for communication with one or more peripheral devices.
#include<MFRC522.h>                                   //Include MFRC522.h library for the RFID-RC522 Module and functions to read data.


#define SS_PIN 10                                      // Defining SS(SDA) pin as 10.
#define RST_PIN 9                                      // Defining RST pin as 9.
#define servopin 8                                     // Defining Servo pin at 8.

int anglei=15;                                         // Initialising initial angle of servo to 15deg.
int anglef=90;                                         // Initialising final angle of servo to 90deg.
int A_delay = 5000;                                    // Declaring the Access delay to be 5 seconds. 
int D_delay = 2000;                                    // Declaring the Denied delay to be 2 seconds.
String card_status;                                    // Declaring two strings, card status and user name.
String user;

Servo myservo;                                         // Instance of servo as myservo
LiquidCrystal my_lcd(6, 7, 5, 4, 3, 2);                // Instance of LiquidCrystal as my_lcd with (rs,enable,d4,d5,d6,d7)
MFRC522 my_mfrc522(SS_PIN, RST_PIN);                   // Instance of MFRC522 as my_mfrc522 with SS pin, RST pin as arguments

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);                                   // Initiate a Serial communication
SPI.begin();                                          // Initiate SPI bus
my_mfrc522.PCD_Init();                                // Initiate MFRC522
my_lcd.begin(16,2);                                   // Initialise the LCD 
pinMode(servopin, OUTPUT);                            // Declaring servopin as Outputs
myservo.attach(servopin);                             // Telling servo is attached at 8 pin
myservo.write(anglei);                                // Writing servo to be at initial angle i.e. 15deg.
delay(10);                                            // wait for 10 micro seconds.
my_mfrc522.PCD_DumpVersionToSerial();// Get the version of RFID module and print in serial monitor (only to check if rfid is connected properly)
my_lcd.setCursor(0,0);                                // set the cursor to (0,0) i.e first line first space on the LCD.
my_lcd.print("  --WELCOME-- ");                       // print welcome in that line on the LCD
print_initial_msg();                                  // calling the function which prints a certain message
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!my_mfrc522.PICC_IsNewCardPresent()){           //Look for new cards and if not found return back
    return;
  }
 if(!my_mfrc522.PICC_ReadCardSerial()){             //Read the Card serial number if present and if unable to read return back
  return;
 }
Serial.print("UID tag :");                          // Show UID on serial monitor (only while testing)
String ID;                                          // Initialise a String with name ID
byte letters;                                       // Initialise a byte with name letters

for(byte i=0;i<my_mfrc522.uid.size;i++){                     // Reading the data from the scanning proccess and from the RFID.
  Serial.print(my_mfrc522.uid.uidByte[i]<0x10 ? "0" : " ");
  Serial.print(my_mfrc522.uid.uidByte[i],HEX);
  ID.concat(String(my_mfrc522.uid.uidByte[i]<0x10 ? "0" : " "));
  ID.concat(String(my_mfrc522.uid.uidByte[i],HEX));
}
Serial.println();                                 
ID.toUpperCase();                                   // Convert the string into all upper case
if (ID.substring(1) == "XX XX XX XX" ){ //To be replaced with tag ID // Check if the UID of the card is in the list of cards having access
 card_status="Access granted";                      // If yes then grant access to the specific user
 user = "Ruthvik";
}
else if (ID.substring(1) == "YY YY YY YY"){  // substring = if the string contains this specific string
card_status="Access granted";
user = "Sugreev";
}
else
{ 
  card_status="Access denied";                   // If the UID of the card is not in the list of cards with access then access is denied
}
my_lcd.clear();                                  // clear the lcd screen
my_lcd.setCursor(0,0);                           // set the cursor to the first point
my_lcd.print(card_status);                       // print the card status on the first line.
my_lcd.clear();                                 // clear the lcd screen again

  if(card_status == "Access granted" ){
    my_lcd.setCursor(0,0);                     // set the cursor to the first point
    my_lcd.print("ID:");                       // print ID: and then from that point print the ID value
    my_lcd.setCursor(3,0);
    my_lcd.print(ID);
    my_lcd.setCursor(0,1);                     // set the cursor to the first space of the next line (0,1)
    my_lcd.print(" Hello ");                   // In the second line start printing hello "user"
    my_lcd.setCursor(7,1);
    my_lcd.print(user);
    myservo.write(anglef);                     // write the servo to the final angle and open the door
    delay(A_delay);                            // wait for access delay i.e. 5 seconds.
    myservo.write(anglei);                     // then write the servo back to initial angle and close the door
  }
  else if(card_status == "Access denied"){
    my_lcd.setCursor(0,0);
    my_lcd.print("Unauthorized card");        // if access is denied then print this message
    myservo.write(anglei);                    // Keep the servo at the initial angle and remain close
    delay(D_delay);                          // wait for denied delay i.e. 2 seconds 
    
  }
my_lcd.clear();                             // clear the lcd screen
delay(2000);                                // wait for 2 seconds and then scan again
}
void print_initial_msg(){
  delay(1000);                             // print this message when called in the void setup
  my_lcd.clear();
  my_lcd.print("-Access Control-");
  my_lcd.setCursor(0,1);
  my_lcd.print(" Scan Your Tag ");
}
