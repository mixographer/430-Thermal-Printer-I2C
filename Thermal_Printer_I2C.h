#ifndef Thermal_Printer_I2C_h
#define Thermal_Printer_I2C_h

#include "Arduino.h"
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





        