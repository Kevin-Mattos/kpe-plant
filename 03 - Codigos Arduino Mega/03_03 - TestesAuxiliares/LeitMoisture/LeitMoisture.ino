//Programa: Monitoracao de planta usando Arduino
//Autor: FILIPEFLOP
 
#define pino_sinal_analogico A0
 
int valor_analogico;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.println("Porta analogica: ");
  Serial.print(valor_analogico);
 
  delay(1000);
}
