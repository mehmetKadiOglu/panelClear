#include "InputOutput.h"
class Hareket{
  public:
    Hareket();
    void hareketBaslat();
  private:
    void yukariHareketBaslat();
    void yukariHareketDongu();
    void asaIn();
    void basaGel();

    Pinler *pinler;
    Pinler * getPinlerNesne();
    void setPinler();

    bool donguKontrol = true;


    
  
  
};
