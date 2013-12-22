#include <Thermal_Printer_I2C.h>
#include <Wire.h>

Thermal_Printer_I2C printer;
boolean goOnce = 1;

void setup(){
  Wire.begin();
  printer.begin(10, 11, 0x20);
}

void printDemo(){
    
    delayMicroseconds(10);
    
    printer.print("This is a test of the thermal printing library. It only works because Rob Tillaart and michinyon continued to");
    printer.println("help me as I bumped around in the dark. Thanks!"); // <----- printer.println, I was using printer.write()
    printer.lineFeed(2);
    //inverse
    printer.inverse();
    printer.println("this should be inversed");
    printer.notInverse();
    printer.lineFeed(2);
    //Bold
    printer.boldOn();
    printer.println("This is Bold!");
    printer.boldOff();
    printer.lineFeed(2);
    //upside down writing
    printer.upsideDown();
    printer.println("This is upside down...");
    printer.lineFeed(3);
    printer.notUpsideDown();
    //Larger size
    printer.printSize(33);
    printer.print("Large Print");
    printer.printSize(00);
    printer.lineFeed(3);
    //alignment options:
    printer.alignCenter();
    printer.print("Centered.");
    printer.lineFeed(1);
    printer.alignRight();
    printer.print("Right alignment");
    printer.lineFeed(1);
    printer.alignLeft();
    //underlined
    printer.underline();
    printer.print("underlined");
    printer.thickUnderline();
    printer.println(" Thick underline");
    printer.lineFeed(1);
    printer.noUnderline();
    //Hello World.
    printer.print("Hello World!");
    printer.lineFeed(10);
    delayMicroseconds(10); 
    printer.lineFeed(4);
    printer.doCut();
    delay(100);
}

void loop(){
    if (goOnce){
       printDemo();
       goOnce = 0;
       }
}
}
