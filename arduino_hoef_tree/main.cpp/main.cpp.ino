#include<stdio.h>
#include"util.h"
#include <WiFi.h>
#include <HTTPClient.h>
int contador = 1;
ARVORE* arv;
ATRIBUTO** atributos;

int HTTP_PORT = 80;
const char* ssid="TAVARES 2.4 OI FIBRA";
const char *password = "13121997";
String HTTP_METHOD = "GET";
char HOST_NAME[] = "http://192.168.1.83:3000/data/";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  WiFi.begin(ssid, password);
  while(WiFi.status()  != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    
    }

  Serial.println("\nComeçou");
    atributos =  criar_instancia_de_atributos();
    arv = criar_arvore(atributos);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  
  contador++;
  Serial.println(contador);
  if (WiFi.status()  ==WL_CONNECTED){
      HTTPClient http;
      String serverpath = HOST_NAME + String(contador);
      Serial.println(serverpath);
      http.begin(serverpath.c_str());
      int respCode = http.GET();
      Serial.println(respCode);
      String payload = http.getString();
      Serial.println(payload);
      http.end();

    }
    
  


}
