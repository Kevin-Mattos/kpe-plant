#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,20,4);

#include <Ultrasonic.h>
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

String incomingByte = "abc\0"; // variável para o dado recebido

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {

  lcd.clear();
  lcd.setCursor(4,1);
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor


//  String outString = "{\"method\": \"detail\", \"json\": {\"name\": \"MEU NOME DO ARDUINO\", \"leitSensor\":" + String(cmMsec) + " }}" ;
//  Serial.print(outString); 

  delay(2500);


  
  // apenas responde quando dados são recebidos:
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    incomingByte = Serial.readString();

    // responde com o dado recebido:
//    Serial.print("I received: ");
//    Serial.println(incomingByte);
    lcd.print(incomingByte);
  }
  }
