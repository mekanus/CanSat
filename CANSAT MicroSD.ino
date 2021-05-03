#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
#include<Wire.h>
//const int MPU=0x68;
//int AcX,AcY,AcZ;

//Pino de conexão do pino CS do modulo
const int chipSelect = 4;

void setup()
{
  Serial.begin(9600); //INICIALIZA A SERIAL
//  Wire.begin();
//    Wire.beginTransmission(MPU);
//  Wire.write(0x6B); 
   
  //Inicializa o MPU-6050
//  Wire.write(0); 
 // Wire.endTransmission(true);

  if (!bmp.begin()){ //SE O SENSOR NÃO FOR INICIALIZADO, FAZ
  Serial.println("Sensor BMP180 não foi identificado! Verifique as conexões."); //IMPRIME O TEXTO NO MONITOR SERIAL
  while(1){} //SEMPRE ENTRE NO LOOP
  }
  Serial.println("CanSat Unigranrio Caxias");
  Serial.println("Inicializando cartao SD...");

  //Inicia a comunicacao com o modulo SD
  if (!SD.begin(chipSelect))
  {
    Serial.println("Falha ao acessar o cartao !");
    Serial.println("Verifique o cartao/conexoes e reinicie o Arduino...");
    return;
  }
  Serial.println("Cartao iniciado corretamente !");
  Serial.println();
}

void loop()
{
  unsigned long currentMillis = millis();

//Wire.beginTransmission(MPU);
//  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
//  Wire.endTransmission(false);
  
  //Solicita os dados do sensor
//  Wire.requestFrom(MPU,14,true);  
//  AcX=Wire.read()<<8|Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
//  AcY=Wire.read()<<8|Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
//  AcZ=Wire.read()<<8|Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  
  //Mostra os dados no Serial Monitor
  Serial.print("Este arduino esta ligado a ");
  Serial.print(currentMillis / 1000);
  Serial.println(" segundos");

    Serial.print("Temperatura: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readTemperature()); //IMPRIME NO MONITOR SERIAL A TEMPERATURA
    Serial.println(" *C (Grau Celsius)"); //IMPRIME O TEXTO NO MONITOR SERIAL
        
    Serial.print("Pressão: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readPressure()); //IMPRIME NO MONITOR SERIAL A PRESSÃO
    Serial.println(" Pa (Pascal)"); //IMPRIME O TEXTO NO MONITOR SERIAL
     
    Serial.print("Altitude: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readAltitude()); //IMPRIME NO MONITOR SERIAL A ALTITUDE APROXIMADA
    Serial.println(" m (Metros)"); //IMPRIME O TEXTO NO MONITOR SERIAL
    
    Serial.print("Pressão a nível do mar (calculada): "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readSealevelPressure()); //IMPRIME NO MONITOR SERIAL A PRESSÃO A NÍVEL DO MAR
    Serial.println(" Pa (Pascal)"); //IMPRIME O TEXTO NO MONITOR SERIAL

    Serial.print("Altitude real: "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.print(bmp.readAltitude(101500)); //IMPRIME NO MONITOR SERIAL A ALTITUDE REAL
    Serial.println(" m (Metros)"); //IMPRIME O TEXTO NO MONITOR SERIAL
     
    Serial.println("-----------------------------------");
    
  //Abre o arquivo datalog.txt
  File dataFile = SD.open("Cansat.txt", FILE_WRITE);

  //Grava as informacoes no arquivo
  if (dataFile)
  {
    dataFile.print("Horimetro: ");
    dataFile.print(currentMillis / 1000);
    dataFile.print(" segundos - ");
//    dataFile.print("Accel Axis X: ");
//    dataFile.print(AcX);
//    dataFile.print(" - Accel Axis Y: ");
//    dataFile.print(AcY);
//    dataFile.print(" - Accel Axis Z: ");
//    dataFile.print(AcZ);
    dataFile.print(" - Temperatura: ");
    dataFile.print(bmp.readTemperature());
    dataFile.print(" Celsius - Pressão: ");
    dataFile.print(bmp.readPressure());
    dataFile.print(" Pascal - Altitude: ");
    dataFile.print(bmp.readAltitude());
    dataFile.print(" metros - Pressao ATM: ");
    dataFile.println(bmp.readPressure()*0.00000986923);

    //Fecha o arquivo
    dataFile.close();
  }

  //Exibe um erro se nao conseguir abrir o arquivo
  else
  {
    Serial.println("Erro ao abrir o arquivo datalog.txt");
  }
  delay(2000);
}
