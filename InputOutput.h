class Pinler{
  public:
    Pinler();
    void sesSensor(char);
    void motorHareket(char, char);
    void motorHareketTemplate();
    int getSesSensorValue();
    int getKontrolSensorValue(char);
    

  private:
    char *motorHareketPin;
    void setMotorHareketPin();
    char getMotorHareketPin(char);
    
    char *sesSensoru;
    void setSesSensor();
    char getSesSensorEleman(char);
    
    int *kontrolSensor;
    void setKontrolSensor();
    int getKontrolSensorEleman(char);
    
    void setHareketTemplateIndex(char);
    int getHareketTemplateIndex();
    
    char hareketTemplateIndex;
    void setFonksiyonlariTemplate();
    void pinBaglanti();
};
