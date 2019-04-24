#include "InputOutput.h"
#include "Arduino.h"
Pinler::Pinler(){
  this->setFonksiyonlariTemplate();
  this->setHareketTemplateIndex(1);
  this->pinBaglanti();
}

void Pinler::setHareketTemplateIndex(char value){
  this->hareketTemplateIndex = value;
}
int Pinler::getHareketTemplateIndex(){
  return this->hareketTemplateIndex;
}


void Pinler::setSesSensor(){
  this->sesSensoru = new char[2];
  this->sesSensoru[0] = 6;
  this->sesSensoru[1] = 7;
}
char Pinler::getSesSensorEleman(char index){
  return this->sesSensoru[index];
}



void Pinler::setKontrolSensor(){
  this->kontrolSensor = new int[3];
  this->kontrolSensor[0] = A1;
  this->kontrolSensor[1] = A3;
  this->kontrolSensor[2] = A2;
  
}

int Pinler::getKontrolSensorEleman(char index){
  return this->kontrolSensor[index];
}

void Pinler::setMotorHareketPin(){
  this->motorHareketPin = new char[5];
  for(char index = 0 ; index < 5 ; index++)
        this->motorHareketPin[index] = index + 8;
}
char Pinler::getMotorHareketPin(char index){
   return this->motorHareketPin[index];
}


void Pinler::setFonksiyonlariTemplate(){

  this->setSesSensor();
  this->setKontrolSensor();
  this->setMotorHareketPin();
  
}

void Pinler::pinBaglanti(){
  for(char index = 0; index < 5 ; index++)
        pinMode(this->getMotorHareketPin(index), OUTPUT);
        
     pinMode(this->getSesSensorEleman(0), OUTPUT);
     pinMode(this->getSesSensorEleman(1), INPUT);
     
}

/////////////////////

void Pinler::sesSensor(char value){
   digitalWrite(this->getSesSensorEleman(0), value);
}

void Pinler::motorHareket(char index, char value){
    digitalWrite(this->getMotorHareketPin(index), value);
}
void Pinler::motorHareketTemplate(){
  this->motorHareket(0, abs(this->getHareketTemplateIndex() - 1));
  this->motorHareket(1, this->getHareketTemplateIndex()); 
  this->motorHareket(4, this->getHareketTemplateIndex());
  this->setHareketTemplateIndex( (this->getHareketTemplateIndex() + 1 ) % 2 );
}

int Pinler::getSesSensorValue(){
    int sure = 0;
    this->sesSensor(0);
    this->sesSensor(1);
    sure = pulseIn(this->getSesSensorEleman(1), HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
    return sure*0.034/2; /* ölçülen sure uzaklığa çevriliyor */ 
}

/*  this->kontrolSensor[0] = A1;
  this->kontrolSensor[1] = A3;
  this->kontrolSensor[2] = A2;
 * 
 * 0. indeks sol
 * 1. indeks yukari
 * 2. indeks aşa
 */
int Pinler::getKontrolSensorValue(char index){
  return analogRead(this->getKontrolSensorEleman(index));
}
