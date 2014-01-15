//
//    FILE:  Thermal_Printer_I2C.h
//  AUTHOR:  Jimmy Patrick
// VERSION:  0.0.11
// PURPOSE:  Controls a Parallel Printer through a PFC8574
//    DATE:  2013-12-18
//     URL:
//
// Released to the public domain. Thanks to Rob Tillaart for helping me get this started. 
//

#ifndef Thermal_Printer_I2C_h
#define Thermal_Printer_I2C_h

#include "Energia.h"
#include <Print.h>

class Thermal_Printer_I2C : public Print
{
    public:
        Thermal_Printer_I2C();
        void printChar(uint8_t toPrint);
        void begin(int, int, byte);
        size_t write(uint8_t); 
        
        void waitForPrinter(int port);
        void doStrobe();
        void setData(char text);
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
        void lineFeed(uint8_t lines);
        void boldOn();
        void boldOff();
        void inverse();
        void notInverse();
        void printSize(byte fontsize);
        void upsideDown();
        void notUpsideDown();  
    private:
};


#endif





        
