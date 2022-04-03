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

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(pino_sinal_analogico, INPUT);

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //Le o valor do pino A0 do Moisture sensor
  MoistureSensor = analogRead(pino_sinal_analogico);


  String outString = "{\"method\": \"detail\", \"json\": {\"plantId\":1,\"internalHumidity\":32,\"externalHumidity\":33,\"temperature\":45,\"luminosity\":23}}" ;
//String outString = "{\"method\": \"detail\", \"json\": {\"name\": \"MEU NOME DO ARDUINO\", \"leitSensor\":" + String(t) + ",  }}" ; //Soma string com a leitura do sensor  
 Serial.println(outString); 
 delay (1000);
}
