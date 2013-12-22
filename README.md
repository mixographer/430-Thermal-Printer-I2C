Thermal-Printer-I2C
===================

Arduino Library for Parallel Printers with Arduno and PFC8574 I/O Expanders or Shift Registers.
___________________________________________________________________________
 
This is an Arduino Library to use with Parallel-interfaced Thermal Printers. I used 
a PFC8574 I/O Expander to communicate with the Parallel port. This code should work 
with most parallel port receipt printers that use the ESC/POS Communication mode. 

I have also added a library and example file that works with a standard 74HC595 shift
register. If you are tight on space, you might use the 595 (SR) version, it uses less memory
than the Wire Library (I2C) version. 

Rename this directory 'Thermal_Printer_I2C' in your Arduino libraries directory, before you 
start the Arduino IDE. 

ARDUINO LIBRARY LOCATION:

*On your Mac:: In (home directory)/Documents/Arduino/Libraries

*On your PC:: My Documents\Arduino\libraries

*On your Linux box: (home directory)/sketchbook/libraries


---------------------------------------

The example sketches show usage details. Supports Bold, underline, font size, fonta and fontb, 
upsidedown printing, bell, and more. 

This uses an I/O expander, but should be easily adapted to using I/O pins through port manipulation. 

Thanks to Rob Tillaart on the Arduino Forum for helping me get this started. 
