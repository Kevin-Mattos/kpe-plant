#include <Wire.h>;
//#include <DHT.h>
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11

#include <Ultrasonic.h>
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
 

//String incomingByte = "abc\0"; // variável para o dado recebido - Receber dados do Rasp


void setup() {
  Serial.begin(9600);
 // dht.begin();
}

void loop() {


  //Le as informacoes do sensor, em cm e pol
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);



  //Exibe informacoes no serial monitor
 String outString = "{\"method\": \"detail\", \"json\": {\"name\": \"MEU NOME DO ARDUINO\", \"leitSensor\":" + String(cmMsec) + " }}" ; //Soma string com a leitura do sensor
 Serial.print(outString); 

  delay(2500);


  
  // apenas responde quando dados são recebidos:
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    incomingByte = Serial.readString();

    // responde com o dado recebido:
    Serial.print("I received: ");
    Serial.println(incomingByte);
  }
  }
