//
//    FILE:  Thermal_Printer_SR.cpp
//  AUTHOR:  Jimmy Patrick
// VERSION:  0.0.01
// PURPOSE:  Controls a Parallel Printer through a 595 Shift Register
//    DATE:  2013-12-18
//     URL:
//
// Released to the public domain. Thanks to Rob Tillaart for helping me get this started. 
//


#include "Arduino.h"
#include "Thermal_Printer_SR.h"


Thermal_Printer_SR::Thermal_Printer_SR(){
    }
    
    
void Thermal_Printer_SR::begin(int latchPin, int dataPin, int clockPin, int strobePin, int busyPin){
    //shift register pins
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);  
    pinMode(clockPin, OUTPUT);
    //printer pins
    pinMode(strobePin, OUTPUT);
    digitalWrite(strobePin, HIGH);
    pinMode(busyPin, INPUT);
    digitalWrite(busyPin, LOW);
    
    printChar((byte)0x1B);
    printChar((byte)0x40);
    _latchPin = latchPin;
    _clockPin = clockPin;
    _dataPin = dataPin;
    delay(200);
    }
    
void Thermal_Printer_SR::printChar(uint8_t toPrint){
  //do the shift register one bytes worth here:
  //update Shift Register
    digitalWrite(_latchPin, LOW);
    shiftOut(_dataPin, _clockPin, MSBFIRST, toPrint);
    digitalWrite(_latchPin, HIGH);
  //Then pulse the strobe here:
    waitForPrinter(12);
    digitalWrite(10, LOW);
  //delayMicroseconds(100);
    digitalWrite(10, HIGH);
    delayMicroseconds(5);
}

// these are all the features I'm trying to add:

void Thermal_Printer_SR::waitForPrinter(int port){
  while(digitalRead(port) == 1){
     // wait for busy to go low
  }
}

void Thermal_Printer_SR::doStrobe(){
  digitalWrite(10, LOW);
  delayMicroseconds(10);
  digitalWrite(10, HIGH);
  }
  
void Thermal_Printer_SR::initializePrinter(){
  printChar((byte)0x1B);
  printChar((byte)0x40);
}

void Thermal_Printer_SR::alignCenter(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(1);
}

void Thermal_Printer_SR::alignRight(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(2);
}

void Thermal_Printer_SR::alignLeft(){
  printChar((byte)0x1B);
  printChar((byte)0x61);
  printChar(0);
}
  

void Thermal_Printer_SR::underline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(1);
}

void Thermal_Printer_SR::thickUnderline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(2);
}

void Thermal_Printer_SR::noUnderline(){
  printChar((byte)0x1B);
  printChar((byte)0x2D);
  printChar(0);
}


void Thermal_Printer_SR::doCut(){
  printChar((byte)0x1D);
  printChar((byte)0x56);
  printChar(49);
}

//Do the buzzer in increments of 200ms
void Thermal_Printer_SR::doBuzzer(int repeat){
  for (int i = 0; i < repeat; i++){ 
    printChar((byte)0x1B);
    printChar((byte)0x1E);
    printChar(49);
  } 
}


//Select  the font. Valid params are 0 or 1
void Thermal_Printer_SR::fontA(){
  printChar((byte)0x1B);
  printChar((byte)0x4D);
  printChar(0);
}

void Thermal_Printer_SR::fontB(){
  printChar((byte)0x1B);
  printChar((byte)0x4D);
  printChar(1);
}

//Line feed (the number of lines to feed) 
void Thermal_Printer_SR::lineFeed(uint8_t lines){
  printChar((byte)0x1B);
  printChar((byte)0x64);
  printChar(lines);
}
  
void Thermal_Printer_SR::boldOn(){
  printChar((byte)0x1B);
  printChar((byte)0x45);
  printChar(1);
}

void Thermal_Printer_SR::boldOff(){
  printChar((byte)0x1B);
  printChar((byte)0x45);
  printChar(0);
}

void Thermal_Printer_SR::inverse(){
  printChar((byte)0x1D);
  printChar((byte)0x42);
  printChar(1);
}

void Thermal_Printer_SR::notInverse(){
  printChar((byte)0x1D);
  printChar((byte)0x42);
  printChar(0);
}

//I don't understand the font size description in the manual. 
// fontsize 00 = standard, and the size changes based on this byte, 
// MSB is Horizontal and LSB is Vertical
// 22 is larger, 33 is even larger. Needs work.
void Thermal_Printer_SR::printSize(byte fontsize){
  printChar((byte)0x1D);
  printChar((byte)0x21);
  printChar(fontsize);
}

void Thermal_Printer_SR::upsideDown(){
  printChar((byte)0x1B);
  printChar((byte)0x7B);
  printChar(1);
}

void Thermal_Printer_SR::notUpsideDown(){
  printChar((byte)0x1B);
  printChar((byte)0x7B);
  printChar(0);
}
// to here

size_t Thermal_Printer_SR::write(uint8_t c){
    printChar(c);
    return 1; 
}

