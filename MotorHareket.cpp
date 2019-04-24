#include "MotorHareket.h"
#include "Arduino.h"
Hareket::Hareket(){
  this->setPinler();
}
void Hareket::setPinler(){
  this->pinler = new Pinler();
}
Pinler * Hareket::getPinlerNesne(){
  return this->pinler;
}

void Hareket::yukariHareketBaslat(){
  this->getPinlerNesne()->motorHareketTemplate();
  this->getPinlerNesne()->getSesSensorValue();
  this->getPinlerNesne()->motorHareket(2, HIGH); // saga gidis komutu

  this->yukariHareketDongu();
  
  this->getPinlerNesne()->sesSensor(0);
}

void Hareket::yukariHareketDongu(){
    int mesafe = 0;
    bool kontrol = true; 
    
      while( this->getPinlerNesne()->getKontrolSensorValue(1) != 1023 ){

       if(kontrol){            
         if ( this->getPinlerNesne()->getSesSensorValue() > 20 )
         {
             this->getPinlerNesne()->motorHareket(2, LOW);
            if( mesafe < 100 ) // gidilen mesafe eğer az ise, temizlemesine gerek yok.
            {
              this->basaGel();
              break;
            }
            else{
                kontrol = false;
            }
         }
         else if( ++mesafe >= 1385 )
         {
            //25
            //55
            this->getPinlerNesne()->motorHareket(2, LOW); // sag motor kapatıldı
            kontrol = false;
         }
        // delay();
       }
    }
}
/* motor hareket indeksleri
 *  0. index yukari
 * 1. index asagi
 * 2. index saga
 * 3. index sola
 * 4. index firca
 * 
 * 
 * sensörler
 *  * 0. indeks sol
 * 1. indeks yukari
 * 2. indeks aşa
 *  */
void Hareket::asaIn(){
    this->getPinlerNesne()->motorHareketTemplate();
    while( this->getPinlerNesne()->getKontrolSensorValue(2) != 1023 );
}

void Hareket::basaGel(){
    this->getPinlerNesne()->motorHareket(3, 1);
    this->getPinlerNesne()->motorHareket(0, 0);
    while(this->getPinlerNesne()->getKontrolSensorValue(0) != 1023); // burası analog sensör okuması olacak
    this->getPinlerNesne()->motorHareket(3, 0);

    this->donguKontrol = false;
}
//////////////////////
void Hareket::hareketBaslat(){
  
    this->getPinlerNesne()->motorHareket(0, 1);
    while( this->getPinlerNesne()->getKontrolSensorValue(1) != 1023 );
  
    while(this->donguKontrol){
      this->asaIn();
      this->yukariHareketBaslat();
    }

    this->donguKontrol = true;
}
