
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

//typedef struct{
//  float Temperatura1;
//  float Pressao1;
//  float Altitude1;
//  float ATM1;
//  float AcX1;
//  float AcY1;
//  float AcZ1;
//  }
//A_t;

typedef struct{
  int Temperatura2;
  int Pressao2;
  float Altitude2;
  float ATM2;
  float AcX2;
  float AcY2;
  float AcZ2;
}
B_t;

//A_t Cansat1;  
B_t Cansat2;

RF24 radio(9,10);   // make sure this corresponds to the pins you are using
const uint64_t pipes[2] = { 
  0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
}

void loop(void)
{ 
  // we need data to sent...
//  Cansat1.Temperatura1 = 1;
//  Cansat1.Pressao1 = 2;
//  Cansat1.Altitude1 = 3;
//  Cansat1.ATM1 = 4;
  // end of analog reading

  // radio stuff
  if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      done = radio.read( &Cansat2, sizeof(Cansat2) );
    }
    radio.stopListening();
//    radio.write( &Cansat1, sizeof(Cansat1) );
//    radio.startListening();
  }
  // end of radio stuff

  // serial print received data 
  Serial.print("Cansat2.Temperatura2 = ");
  Serial.println(Cansat2.Temperatura2);
  Serial.print("Cansat2.Pressao2 = ");
  Serial.println(Cansat2.Pressao2);
  Serial.print("Cansat2.Altitude2 = ");
  Serial.println(Cansat2.Altitude2);
  Serial.print("Cansat2.ATM2 = ");
  Serial.println(Cansat2.ATM2);
  Serial.print("Cansat2.AcX2 = ");
  Serial.println(Cansat2.AcX2);
  Serial.print("Cansat2.AcY2 = ");
  Serial.println(Cansat2.AcY2);
  Serial.print("Cansat2.AcZ2 = ");
  Serial.println(Cansat2.AcZ2);
  // end of serial printing
}
