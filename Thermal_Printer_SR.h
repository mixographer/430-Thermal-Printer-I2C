//
//    FILE:  Thermal_Printer_SR.h
//  AUTHOR:  Jimmy Patrick
// VERSION:  0.0.01
// PURPOSE:  Controls a Parallel Printer through a 595 shift Register
//    DATE:  2013-12-18
//     URL:
//
// Released to the public domain. Thanks to Rob Tillaart for helping me get this started. 
//

#ifndef Thermal_Printer_SR_h
#define Thermal_Printer_SR_h

#include "Energia.h"
#include <Print.h>


class Thermal_Printer_SR : public Print
{
    public:
        Thermal_Printer_SR();
        void printChar(uint8_t toPrint);
        void begin(int, int, int, int, int);
        size_t write(uint8_t); 
        
        void waitForPrinter(int port);
        void doStrobe();
        //void setData(char text);
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
        int _latchPin;
        int _dataPin;
        int _clockPin;
        int _busyPin;
    
    
    
};


#endif





        
