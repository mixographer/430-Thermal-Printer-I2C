#include <Wire.h>

#include <Thermal_Printer_I2C.h>

Thermal_Printer_I2C myPrinter(10, 11, 0x20);
boolean goOnce = 1;

void setup(){
   
}

void printDemo(){
   myPrinter.write('This string of numbers should wrap:');
   myPrinter.lineFeed(2);
   
   myPrinter.write('012345678901234567890123456789012345678901234567890....');
   myPrinter.lineFeed(2);
   
   myPrinter.fontA();
   myPrinter.write('This is font A.');
   myPrinter.fontB();
   myPrinter.write('and this is font B.');
   myPrinter.fontA();
   myPrinter.lineFeed(1);
   
   myPrinter.write('This is normal text that is a long string');
   myPrinter.lineFeed(1);
   
   myPrinter.alignRight();
   myPrinter.write('Right aligned');
   myPrinter.lineFeed(1);
   
   myPrinter.alignCenter();
   myPrinter.write('Centered text');
   myPrinter.lineFeed(1);
   myPrinter.alignLeft();
   
   myPrinter.upsideDown();
   myPrinter.write('Upside down text?');
   myPrinter.notUpsideDown();
   myPrinter.lineFeed(2);
   myPrinter.alignLeft();
   
   myPrinter.boldOn();
   myPrinter.write('This is a string in Bold font for emphasis.');
   myPrinter.boldOff();
   myPrinter.lineFeed(1);
   
   myPrinter.underline();
   myPrinter.write('Testing the underline function');
   myPrinter.noUnderline();
   myPrinter.lineFeed(1);
   
   myPrinter.inverse();
   myPrinter.write('This is a Test! (Inverse)');
   myPrinter.notInverse();
   myPrinter.lineFeed(2);
   
   myPrinter.write('this is not inverse');
   myPrinter.lineFeed(2);
   
   myPrinter.printSize(0x22);
   myPrinter.write('This should be 3x printing');
   myPrinter.lineFeed(4);
   
   myPrinter.boldOn();
   myPrinter.underline();
   myPrinter.write('and Bold');
   myPrinter.boldOff();
   myPrinter.noUnderline();
   myPrinter.printSize(00);
   myPrinter.lineFeed(10);
   myPrinter. doCut();
}



void loop(){
//  myPrinter.write('This is a string of chars');goOnce = 0
//  myPrinter.lineFeed(10);
//  myPrinter.doCut();
  delay(20000);
  
  
  if (goOnce){
    printDemo();
    delay(10000);
    goOnce = 0;
  }
  
  
  
}


