#include <Wire.h>
#include <Thermal_Printer_I2C.h>

boolean goOnce = 1;

Thermal_Printer_I2C printer(10, 11, 0x20);

void setup(){
   printer.begin(10, 11, 0x20);
}

void loop(){
  if (goOnce){
    printer.println("Hello World from the Termal Printer I2C library.");
    printer.lineFeed(10);
    printer.doCut();
    goOnce = 0;
    }
  delay (1000);
}
