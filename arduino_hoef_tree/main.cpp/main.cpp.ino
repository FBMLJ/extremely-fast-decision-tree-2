#include<stdio.h>
#include"util.h"
#include <WiFi.h>
#include <HTTPClient.h>
int contador = 0;
#include<stdlib.h>
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
  delay(200);
  
  contador++;
//  Serial.println(contador);
  if (WiFi.status()  ==WL_CONNECTED){
      HTTPClient http;
      String serverpath = HOST_NAME + String(contador);

      http.begin(serverpath.c_str());
      int respCode = http.GET();
      String payload = http.getString();
      int controlador = 9, atual = 0;
      int* vetor = (int*) malloc(sizeof(int)*5);
      String temp = "";
      while (payload[controlador] != '}'){
        if (payload[controlador] == ',' || payload[controlador] == ']'){

          vetor[atual++] = temp.toInt();
          temp ="";  
        } else
        temp += payload[controlador];
        controlador++;
       }
//       Serial.println(vetor[0]);
//       Serial.println(vetor[1]);
//       Serial.println(vetor[2]);
//       Serial.println(vetor[3]);
//       Serial.println(vetor[4]);
//       Serial.println(contador);
//       Serial.println("---");
       int valor_previsto = predict(vetor,arv,atributos);
//       Serial.print(vetor[4]);
      Serial.print(valor_previsto);
       Serial.print(" , ");
       Serial.println(vetor[4]);
//       Serial.print(" , ");
//       Serial.println(vetor[4] == valor_previsto);
       adiciona_na_arvore(vetor,arv,atributos);
       free(vetor);
      http.end();

    }
    
  


}
