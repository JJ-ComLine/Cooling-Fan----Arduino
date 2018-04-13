#include <dht11.h>
#include <LiquidCrystal.h>  
dht11 DHT;
#define DHT11_PIN 13

int motoreDC = 9;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 



void setup(){
  
  pinMode(motoreDC, OUTPUT);
  
  Serial.begin(9600);

  lcd.begin(16, 2);  
  lcd.print("H(%):");
  lcd.setCursor(0,1);
  lcd.print("T(C):");

}
 
void loop(){
  
 
  
  int chk;
  //Serial.print("DHT11, \t");
  chk = DHT.read(DHT11_PIN); 
  
  switch (chk){
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
 // DISPLAT DATA

  
  lcd.setCursor(0,0); 
  lcd.print("H(%): ");
  lcd.print(DHT.humidity,DEC);
  
  //Serial.print(",\t");
  
  lcd.setCursor(0,1);
  lcd.print("T(C): ");
  lcd.print(DHT.temperature,DEC);

  if (DHT.humidity > 70 || DHT.temperature > 26)
    digitalWrite(motoreDC, HIGH);
  else 
    digitalWrite(motoreDC, LOW);
 
  delay(500);
}

