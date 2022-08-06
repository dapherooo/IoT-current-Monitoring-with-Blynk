#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <EmonLib.h>

char auth[] = "EFNbqtnB2dDNFFuwaBz70pDzvwS1cTgD";
char ssid[] = "IoT";
char pass[] = "skripsi2021";

EnergyMonitor emon1;
EnergyMonitor emon2;
EnergyMonitor emon3;
EnergyMonitor emon4;

int pin_sct1 = A0;
int pin_sct2 = A1;
int pin_sct3 = A2;
int pin_sct4 = A3; 

#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3); // RX, TX


ESP8266 wifi(&Serial1);

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
  emon1.current(pin_sct1, 40);
  emon2.current(pin_sct2, 52);
  emon3.current(pin_sct3, 55);
  emon4.current(pin_sct4, 57);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 8080);
}

void loop()
{
  double Irms1 = emon1.calcIrms(1480);
  double Irms2 = emon2.calcIrms(1480);
  double Irms3 = emon3.calcIrms(1480);
  double Irms4 = emon4.calcIrms(1480);
  
  
  Serial.print("Arus1: ");
  Blynk.virtualWrite(V1, String(Irms1));
  Serial.println(Irms1);
  Serial.print("Arus2: ");
  Blynk.virtualWrite(V2, String(Irms2));
  Serial.println(Irms2);
  Serial.print("Arus3: ");
  Blynk.virtualWrite(V3, String(Irms3));
  Serial.println(Irms3);
  Serial.print("Arus4: ");
  Blynk.virtualWrite(V4, String(Irms4));
  Serial.println(Irms4);
  Serial.println();
  delay(100);
  
  Blynk.run();
  
}
