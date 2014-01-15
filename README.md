430-Thermal-Printer-I2C
===================

THIS IS A WORK IN PROGRESS, I HAVE NOT TESTED THIS YET IN ENERGIA!!!

Energia Library for Parallel Printers with  launchpad and PFC8574 I/O Expanders or Shift Registers.
___________________________________________________________________________
 
This is a Energia Library to use with Parallel-interfaced Thermal Printers. I used 
a PFC8574 I/O Expander to communicate with the Parallel port. This code should work 
with most parallel port receipt printers that use the ESC/POS Communication mode. 

I have used this library with A CBM-1000 printer, an Epson T88-III printer and a 
Star TSP 800 printer. 

I have also added a library and example file that works with a standard 74HC595 shift
register. If you are tight on space, you might use the 595 (SR) version, it uses less memory
than the Wire Library (I2C) version. 

Rename this directory '430_Thermal_Printer_I2C' in your Energia libraries directory, before you 
start the Energia IDE. 


---------------------------------------

The example sketches show usage details. Supports Bold, underline, font size, fonta and fontb, 
upsidedown printing, bell, and more. 

This uses an I/O expander or a shift register, but should be easily adapted to using I/O pins through port manipulation. 

Thanks to Rob Tillaart on the Arduino Forum for helping me get this started. 
