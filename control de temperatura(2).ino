#include <LiquidCrystal.h>

float temperatura;
float lm35 = 0;
float maxin=5;
int rele=2;
int interruptor=3;
int interruptor1=1;
int led1=0;
int led2=A1;
LiquidCrystal lcd(9,8,7,6,5,4);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(rele, OUTPUT);
pinMode(interruptor,INPUT);
 lcd.begin(16,2);
}

void loop() {
 temperatura = analogRead(lm35);
 temperatura = (temperatura * 5/ 1024) / 0.01;

lcd.clear();
 lcd.home();
 lcd.print("Temperatura:");
 lcd.setCursor(0,1);
 lcd.print(temperatura);
 lcd.print(" grados C");
 delay(500);

 
if(digitalRead(interruptor1)==1 && temperatura<2  )
{
 digitalWrite(rele,HIGH);
digitalWrite(led1,HIGH); 
digitalWrite(led2,LOW); 
 // delay(500);
 }
else
{
if(digitalRead(interruptor)==1 && temperatura<=5  )
{
 digitalWrite(rele,HIGH);
 digitalWrite(led2,HIGH);
digitalWrite(led1,LOW);  
  delay(500);
 }
else
{
 digitalWrite(rele,LOW);
delay(500);
 
}  
 //digitalWrite(rele,LOW);
 //delay(500);
 
}
}
