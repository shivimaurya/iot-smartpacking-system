// Arduino Car Parking System

#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
Servo myservo;
#define ServoM 7
#define Exit 9
#define In 8
#define Pwr 6
#define Gnd 10
#define BarLow 0
#define BarUp 180
#define CAPACITY 7



void setup()
{
   Serial.begin(9600);

  myservo.attach(ServoM);
lcd.begin(16,2);
lcd.print("Space left for ");

pinMode(Gnd, OUTPUT);
pinMode(Pwr, OUTPUT);
pinMode(Exit, INPUT);
pinMode(In, INPUT);

digitalWrite(Gnd, LOW); 
digitalWrite(Pwr, HIGH);

myservo.write(BarLow);

}

int Available= 7;

void loop()
{

 if (Available >= 1)
{

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Space left for"); lcd.setCursor(0,1);
lcd.print (Available);
lcd.print("cars");
}
else
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Sorry!");
lcd.setCursor(0,1);
lcd.print("No place left!");
}
if(digitalRead(In)==1)
{
  if(Available != 0)
   {
Available--;
myservo.write(BarUp);
delay(2000);
myservo.write(BarLow);
    }
} 
if(digitalRead(Exit)==1)
{
  if(Available!= CAPACITY)
   {
   Available++
   myservo.write(BarUp);
   delay(2000);
   myservo.write(BarLow);
  }
}
 
Serial.println(Available);

delay(20);

}