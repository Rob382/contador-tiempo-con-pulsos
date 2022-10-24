#include <Bridge.h>
#include <BridgeClient.h>
#include <BridgeServer.h>
#include <BridgeSSLClient.h>
#include <BridgeUdp.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

byte entrada1 = 0;
byte entrada_1_prev = 0;
unsigned long currentMillis = 0;
unsigned long duracion_0_logico = 0;
unsigned long duracion_1_logico = 0;
unsigned long logico_0_largo = 0;
unsigned long logico_1_largo = 0;
unsigned long pulsacion_previa = 0;
byte logico_0_pulso_largo_prev = false;
byte logico_1_pulso_largo_prev = false;

void setup() {
  // put your setup code here, to run once:
Bridge.begin();       //Puente entre el MCU y el MPU.
Console.begin();
  pinMode(entrada1, INPUT);          // set buttonPin as input
  Console.println("Press button");
}

void loop() {
  // put your main code here, to run repeatedly:
currentMillis = millis();

if (currentMillis - pulsacion_previa > 50){
  entrada1 = digitalRead(3);

if (entrada1 == HIGH && entrada_1_prev == false){
  entrada_1_prev = true;
  duracion_1_logico = currentMillis;
}
if (entrada1 == LOW && entrada_1_prev == true){
  entrada_1_prev = false;
  duracion_0_logico = currentMillis;

  Console.println(duracion_0_logico - duracion_1_logico);
  Console.println(" ms");
  
}
  
  
  pulsacion_previa = currentMillis;
}
}
