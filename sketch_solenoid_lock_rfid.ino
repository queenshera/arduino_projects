#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#define SS_PIN 10
#define RST_PIN 9
#define ARRAYSIZE 10
#define door 2

LiquidCrystal_I2C lcd(0x27,16,2); 
MFRC522 mfrc522(SS_PIN, RST_PIN);
int counter;
boolean invalidCard = true;

char *accessCards[] = { "2101247828", "2101619028", "2106413728" };

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(door,OUTPUT);
  digitalWrite(door, HIGH);
  lcd.init();
  lcd.backlight();
  welcome();
}
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
 
  Serial.println("this is ok"); 
  String content= "";
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
    content.concat(String(mfrc522.uid.uidByte[i], DEC));
  }
  content.toUpperCase();
  Serial.println(content);

  for(int i=0;i<sizeof(accessCards);i++)
  {
    if ((String)accessCards[i] == content)
    {
      invalidCard = false;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("ACCESS GRANTED");
      counter=0;
      digitalWrite(door, LOW);
      delay(5000);
      digitalWrite(door, HIGH);
      welcome();
    }
  }
  
  /*if (content == "2101247828")
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("ACCESS GRANTED");
    counter=0;
    digitalWrite(2, LOW);
    delay(5000);
    digitalWrite(2, HIGH);
    welcome();
  }*/
  
  if(invalidCard) {
    counter+=1;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("INCORRECT TAG");
    lcd.setCursor(3,1);
    lcd.print("TRY AGAIN");
    delay(2000);
    welcome();
  }
  invalidCard = true;
  
  if(counter>=3)
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("LIMIT EXCEEDED");
    lcd.setCursor(2,1);
    lcd.print("RESET SYSTEM");
  }
}

void welcome()
{
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("WELCOME USER");
  lcd.setCursor(1,1);
  lcd.print("SCAN YOUR CARD");
}
