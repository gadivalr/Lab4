#include <MD_MAX72xx.h>
#include <SPI.h>

#define hardware MD_MAX72XX::GENERIC_HW
#define pinDIN 11
#define pinCS 10
#define pinCLK 13

MD_MAX72XX mx = MD_MAX72XX(hardware,pinDIN,pinCLK,pinCS,1);

const int botonPin1 = 3;  
const int botonPin2 = 2;
int contador = 0;         
int estadoAnterior = HIGH; 

void setup() {
  mx.begin();
  
  mx.setChar(5,'0');
  pinMode(botonPin1, INPUT_PULLUP); 
  pinMode(botonPin2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int estadoActual = digitalRead(botonPin1);
  

  if (estadoAnterior == HIGH && estadoActual == LOW) {
    mx.clear();
    contador++;
    if(contador>15) contador = 0;
    if (contador <= 9){
        mx.setChar(5,'0'+contador);
    }
    else if (contador>=10 && contador<=15){
      mx.setChar(5,'7'+ contador);
    }
    
    Serial.println(contador);
    delay(200); 
    
  }
  
  estadoAnterior = estadoActual; 
  int estadoActual2 = digitalRead(botonPin2);

  if (estadoAnterior == HIGH && estadoActual2 == LOW) {
    mx.clear();
    contador--;
    if(contador<0) contador = 15;
        if (contador > 9){
        mx.setChar(5,'7'+contador);
    }
    else if (contador<=9 && contador>=0){
      mx.setChar(5,'0'+ contador);
    }
    Serial.println(contador);
    delay(200);
  }
}