//
//    FILE:  Thermal_Printer_I2C.cpp
//  AUTHOR:  Jimmy Patrick
// VERSION:  0.0.01
// PURPOSE:  Controls a Parallel Printer through a PFC8574
//    DATE:  2013-12-18
//     URL:
//
// Released to the public domain
//


#include "Arduino.h"
#include "Thermal_Printer_I2C.h"
#include "Wire.h"


#define ESCAPE 0x1B;
#define GS 0x1D;


Thermal_Printer_I2C::Thermal_Printer_I2C(int strobePin, int busyPin, byte i2c_addr){
    Wire.begin(i2c_addr);
    pinMode(strobePin, OUTPUT);
    pinMode(busyPin, INPUT);
    digitalWrite(strobePin, HIGH);
    initializePrinter();
    _strobeWait = 10;
    _busyPin = busyPin;
    _strobePin = strobePin;
    _i2c_addr = i2c_addr;
    delay(500);
    }
    
    
    
void Thermal_Printer_I2C::waitForPrinter(int port){
  while(digitalRead(port) == 1){
     // wait for busy to go low
  }
}

void Thermal_Printer_I2C::doStrobe(){
  digitalWrite(_strobePin, LOW);
  delayMicroseconds(_strobeWait);
  digitalWrite(_strobePin, HIGH);
  }
  
void Thermal_Printer_I2C::setData(char text){
  Wire.beginTransmission(_i2c_addr);
  Wire.write(text);
  Wire.endTransmission();
  doStrobe();
}

void Thermal_Printer_I2C::printChar(char toPrint){
  waitForPrinter(_busyPin);
  setData(toPrint);
  doStrobe();  
}

void Thermal_Printer_I2C::initializePrinter(){
  printChar((byte)0x1B);
  printChar((byte)0x40);
}

void Thermal_Printer_I2C::alignCenter(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(1);
}

void Thermal_Printer_I2C::alignRight(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(2);
}

void Thermal_Printer_I2C::alignLeft(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(0);
}
  

void Thermal_Printer_I2C::underline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(1);
}

void Thermal_Printer_I2C::thickUnderline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(2);
}

void Thermal_Printer_I2C::noUnderline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(0);
}


void Thermal_Printer_I2C::doCut(){
  printChar((byte)0x1D);
  printChar((byte)0x56);
  printChar(49);
}

//Do the buzzer in increments of 200ms
void Thermal_Printer_I2C::doBuzzer(int repeat){
  for (int i = 0; i < repeat; i++){ 
    printChar((byte)0x1B);
    printChar((byte)0x1E);
    printChar(49);
  } 
}

//Select  the font. Valid params are 0 or 1
void Thermal_Printer_I2C::fontA(){
  printChar((byte)0x1B);
  printChar((byte)0x4D);
  printChar(0);
}

void Thermal_Printer_I2C::fontB(){
  printChar((byte)0x1B);
  printChar((byte)0x4D);
  printChar(1);
}

//Line feed (the number of lines to feed) 
void Thermal_Printer_I2C::lineFeed(int lines){
  printChar((byte)0x1B);
  printChar((byte)0x64);
  printChar(lines);
}
  
void Thermal_Printer_I2C::boldOn(){
  printChar((byte)0x1B);
  printChar((byte)0x45);
  printChar(1);
}

void Thermal_Printer_I2C::boldOff(){
  printChar((byte)0x1B);
  printChar((byte)0x45);
  printChar(0);
}

void Thermal_Printer_I2C::inverse(){
  printChar((byte)0x1D);
  printChar((byte)0x42);
  printChar(1);
}

void Thermal_Printer_I2C::notInverse(){
  printChar((byte)0x1D);
  printChar((byte)0x42);
  printChar(0);
}

//I don't understand the font size description in the manual. 
// fontsize 00 = standard, and the size changes based on this byte, 
// MSB is Horizontal and LSB is Vertical
// 22 is larger, 33 is even larger. Needs work.
void Thermal_Printer_I2C::printSize(byte fontsize){
  printChar((byte)0x1D);
  printChar((byte)0x21);
  printChar(fontsize);
}

void Thermal_Printer_I2C::upsideDown(){
  printChar((byte)0x1B);
  printChar((byte)0x7B);
  printChar(1);
}

void Thermal_Printer_I2C::notUpsideDown(){
  printChar((byte)0x1B);
  printChar((byte)0x7B);
  printChar(0);
}


