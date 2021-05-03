#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <Wire.h> 
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;

RF24 radio(9,10);  // make sure this corresponds to the pins you are using
const uint64_t pipes[2] = { 
  0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

const int led = 0;

const int MPU=0x68;
int AcX2,AcY2,AcZ2;

typedef struct{
  float Temperatura1;
  float Pressao1;
  float Altitude1;
  float ATM1;
  float AccelX1;
  float AccelY1;
  float AccelZ1;}
A_t;

typedef struct{
  int Temperatura2;
  int Pressao2;
  float Altitude2;
  float ATM2;
  float AccelX2;
  float AccelY2;
  float AccelZ2;
}
B_t;

A_t Cansat1;  
B_t Cansat2; 

void setup()
{
  Serial.begin(9600);
    Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
   
  //Inicializa o MPU-6050
  Wire.write(0); 
  Wire.endTransmission(true);
  bmp.begin();
  pinMode(led, OUTPUT);
  radio.begin();
  radio.openWritingPipe(pipes[0]);
  radio.openReadingPipe(1,pipes[1]);
}

void loop(void)
{

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);
  AcX2=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY2=Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ2=Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  
  // we need data to sent...
  Cansat2.Temperatura2 = bmp.readTemperature();
  Cansat2.Pressao2 = bmp.readPressure();
  Cansat2.Altitude2 = bmp.readAltitude();
  Cansat2.ATM2 = bmp.readSealevelPressure();
  Cansat2.AccelX2 = AcX2;
  Cansat2.AccelY2 = AcY2;
  Cansat2.AccelZ2 = AcZ2;
  // end of analog reading

  // radio stuff
//  radio.stopListening();
  bool ok = radio.write( &Cansat2, sizeof(Cansat2) );
//  radio.startListening();
/*
  unsigned long started_waiting_at = millis();
  bool timeout = false;
  while ( ! radio.available() && ! timeout )
    if (millis() - started_waiting_at > 250 )
      timeout = true;

  if ( timeout )
  {
    Serial.println("Failed, response timed out.");
    digitalWrite(led, HIGH);
  }
  else
  {
    radio.read( &Cansat1, sizeof(Cansat1) );
    digitalWrite(led, LOW);
  }
  // end of radio stuff
*/
 /*/ serial print received data 
  Serial.print("Cansat1.Temperatura1 = ");
  Serial.println(Cansat1.Temperatura1);
  Serial.print("Cansat1.Pressao1 = ");
  Serial.println(Cansat1.Pressao1);
  Serial.print("Cansat1.Altitude1 = ");
  Serial.println(Cansat1.Altitude1);
  Serial.print("Cansat1.ATM1 = ");
  Serial.println(Cansat1.ATM1);
*/
  // end of serial printing

}
