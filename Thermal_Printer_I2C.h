//
//    FILE:  Thermal_Printer_I2C.h
//  AUTHOR:  Jimmy Patrick
// VERSION:  0.0.01
// PURPOSE:  Controls a Parallel Printer through a PFC8574
//    DATE:  2013-12-18
//     URL:
//
// Released to the public domain
//


#ifndef Thermal_Printer_I2C_h
#define Thermal_Printer_I2C_h

#include "Arduino.h"

class Thermal_Printer_I2C : public Print
{
    public:
        Thermal_Printer_I2C(int strobePin, int busyPin, byte i2c_addr);
        void waitForPrinter(int port);
        void doStrobe();
        void setData(char text);
        void printChar(char toPrint);
        void initializePrinter();
        void alignCenter();
        void alignRight();
        void alignLeft();
        void underline();
        void thickUnderline();
        void noUnderline();
        void doCut();
        void doBuzzer(int repeat);
        void fontA();
        void fontB();
        void lineFeed(int lines);
        void boldOn();
        void boldOff();
        void inverse();
        void notInverse();
        void printSize(byte fontsize);
        void upsideDown();
        void notUpsideDown();
        size_t write(uint8_t data) { printChar(data);  return 1; }
    private:
        int _busyPin;
        int _strobePin;
        byte _i2c_addr;
        int _strobeWait;
};
        
        
        
#endif