//Include Libraries
#include <Wire.h>;
#include "DHT.h"


//Define Pins DHT11
#define DHTPIN A1 // pino conectado
#define DHTTYPE DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//Define Moisture Sensor
#define pino_sinal_analogico A0
int MoistureSensor;
int HP;

//Define LDR Sensor
const int PinoLDR = A5;
int LDRSensor;
int LP;

int Umidade () {
  HP = (MoistureSensor/1024)*100;
  return HP;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(pino_sinal_analogico, INPUT); //Sensor de Umidade do solo
  pinMode(PinoLDR, INPUT); //Sensor de luminosidade
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //Le o valor do pino A5 do LDR
  LDRSensor = analogRead(PinoLDR);

  //Le o valor do pino A0 do Moisture sensor
  MoistureSensor = analogRead(pino_sinal_analogico);



  String outString = "{\"method\": \"detail\", \"json\": {\"plantId\":1,\"internalHumidity\":" + String(Umidade()) + ",\"externalHumidity\":" + String(h) + ",\"temperature\":" + String(t) + ",\"luminosity\":" + String(LDRSensor) + "}}" ;
//  String outString = "{\"method\": \"detail\", \"json\": {\"name\": \"MEU NOME DO ARDUINO\", \"leitSensor\":" + String(t) + ",  }}" ; //Soma string com a leitura do sensor  
 Serial.println(outString); 
 delay (1000);
}