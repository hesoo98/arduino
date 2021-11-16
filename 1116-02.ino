#include <DHT11.h>
#include <LiquidCrystal_I2C.h>//LiquidCrystal 라이브러리 추가
LiquidCrystal_I2C lcd(0x27, 16, 2);//lcd 객체 선언
int pin = 4;
DHT11 dht11(pin);

void setup() {
  lcd.init();//lcd사용시작
  Serial.begin(9600);
  lcd.backlight();
  while(!Serial){
    ;//Wait for serial port to connect. Needed for Lenardo only
  }
}

void loop() {
  int err;
  float temp, humi;

  if((err=dht11.read(humi, temp))==0){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("temp:");
    lcd.print(temp);
    lcd.print('C');
    lcd.setCursor(3,1);
    lcd.print("humi:");
    lcd.print(humi);
    lcd.print('%');
    delay(1000);
  }
  else{
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Error");
    delay(1000);
  }
}
