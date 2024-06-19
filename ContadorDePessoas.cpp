//Código contador de pessoas em um ambiente utilizando matriz de led 8x8, desenvolvido por Nicole Hemp para o projeto final de Sistemas Digitais!

#include <stdio.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW

#define MAX_DEVICES 4
#define CLK_PIN   7
#define DATA_PIN  5
#define CS_PIN    6

#define LED 2
#define LED2 3
#define LDR A0
#define LDR2 A1
#define CLK A2
#define RESET A3
#define UP 4
#define EN 8
#define IN 9
#define Q1 10 
#define Q2 11
#define Q3 12
#define Q4 13

MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

int decimal;
int q1=0, q2=0, q3=0, q4=0;

void clock();
int BCD(int a, int b, int c, int d);
void led1();
void led2();
void imprimeMatriz(int x);

void setup() {
  Serial.begin(9600);

  P.begin();

  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(LDR2, INPUT);

  attachInterrupt(digitalPinToInterrupt(LED), led1, RISING);
  attachInterrupt(digitalPinToInterrupt(LED2), led2, RISING);

  pinMode(CLK, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(IN, OUTPUT);
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);

  digitalWrite(Q1, 0);
  digitalWrite(Q2, 0);
  digitalWrite(Q3, 0);
  digitalWrite(Q4, 0);
  digitalWrite(RESET, 1);
}

void loop() {
  
  imprimeMatriz(decimal);
  //delay(1000);
  
  digitalWrite(RESET, 0);
  digitalWrite(EN, 0);
  digitalWrite(IN, 0);

  attachInterrupt(digitalPinToInterrupt(LED), led1, RISING);
  attachInterrupt(digitalPinToInterrupt(LED2), led2, RISING);

  int leitura = analogRead(LDR);
  int leitura2 = analogRead(LDR2);
  
  //Serial.println(leitura);

  if (leitura<100) {
    Serial.println(leitura);
    digitalWrite(LED, HIGH);  
  } else {
    digitalWrite(LED, LOW);
  }

  if (leitura2<100) {
    digitalWrite(LED2, HIGH); 
  } else {
    digitalWrite(LED2, LOW);
  }
}

void led1 () {
  detachInterrupt(digitalPinToInterrupt(LED2));
  Serial.println("PESSOA ENTROU!");
  digitalWrite(UP, 1);
  clock();

  q1 = digitalRead(Q1);
  q2 = digitalRead(Q2);
  q3 = digitalRead(Q3);
  q4 = digitalRead(Q4);

  decimal = BCD(q1, q2, q3, q4);
  Serial.println(q1);
  Serial.println(q2);
  Serial.println(q3);
  Serial.println(q4);
  Serial.println(decimal);
  delay(1000);
}

void led2 () {
  detachInterrupt(digitalPinToInterrupt(LED));
  Serial.println("PESSOA SAIU!");

  digitalWrite(UP, 0);
  clock();

  q1 = digitalRead(Q1);
  q2 = digitalRead(Q2);
  q3 = digitalRead(Q3);
  q4 = digitalRead(Q4);

  decimal = BCD(q1, q2, q3, q4);
  Serial.println(q1);
  Serial.println(q2);
  Serial.println(q3);
  Serial.println(q4);
  Serial.println(decimal);
  delay(1000);
}

void clock() {
  digitalWrite(CLK, LOW);
  delay(500);
  digitalWrite(CLK, HIGH);
  delay(500);
}

int BCD(int a, int b, int c, int d) {
  if (a==0 && b==0 && c==0 && d==0){
    return 0;
  } else if (a==1 && b==0 && c==0 && d==0){
    return 1;
  }else if (a==0 && b==1 && c==0 && d==0){
    return 2;
  }else if (a==1 && b==1 && c==0 && d==0){
    return 3;
  }else if (a==0 && b==0 && c==1 && d==0){
    return 4;
  }else if (a==1 && b==0 && c==1 && d==0){
    return 5;
  }else if (a==0 && b==1 && c==1 && d==0){
    return 6;
  }else if (a==1 && b==1 && c==1 && d==0){
    return 7;
  }else if (a==0 && b==0 && c==0 && d==1){
    return 8;
  }else if (a==1 && b==0 && c==0 && d==1){
    return 9;
  }
}

void imprimeMatriz(int x) {
  switch (x) {
    case 0:
    if (P.displayAnimate())
    P.displayText("Zero", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 1:
    if (P.displayAnimate())
    P.displayText("Uma", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 2:
    if (P.displayAnimate())
    P.displayText("Duas", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 3:
    if (P.displayAnimate())
    P.displayText("Tres", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 4:
    if (P.displayAnimate())
    P.displayText("Quatro", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 5:
    if (P.displayAnimate())
    P.displayText("Cinco", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 6:
    if (P.displayAnimate())
    P.displayText("Seis", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 7:
    if (P.displayAnimate())
    P.displayText("Sete", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 8:
    if (P.displayAnimate())
    P.displayText("Oito", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;

    case 9:
    if (P.displayAnimate())
    P.displayText("Nove", PA_CENTER, P.getSpeed(), P.getPause(), PA_SCROLL_DOWN, PA_SCROLL_UP);
    delay(200);
    break;
  }
}