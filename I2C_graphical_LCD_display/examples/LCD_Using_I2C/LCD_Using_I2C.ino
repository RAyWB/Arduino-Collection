
// Demo of KS0108B graphics LCD screen connected to MCP23017 16-port I/O expander

// Author: Nick Gammon
// Date: 14 February 2011


#include <Wire.h>
#include <SPI.h>
#include <I2C_graphical_LCD_display.h>

I2C_graphical_LCD_display lcd;

char buf[40];
// example bitmap
byte picture [] PROGMEM = {
 0x1C, 0x22, 0x49, 0xA1, 0xA1, 0x49, 0x22, 0x1C,  // face  
 0x10, 0x08, 0x04, 0x62, 0x62, 0x04, 0x08, 0x10,  // star destroyer
 0x4C, 0x52, 0x4C, 0x40, 0x5F, 0x44, 0x4A, 0x51,  // OK logo
};


void setup () 
{
  lcd.begin ();  
/*
  // draw all available letters
  for (int i = 0x00 ; i <= 0xFf; i++)
  {delay(3);
  sprintf(buf,"Zeichen%3d :  ",i);
  lcd.gotoxy (5, 0);
  lcd.string(buf);
  lcd.gotoxy (80, 0);
  lcd.letter (i);
delay(2);}
    */
    

  // black box  
//  lcd.clear (6, 40, 30, 63, 0xFF);
// delay(2000);
  // draw text in inverse
  lcd.clear();
  lcd.gotoxy (2,62);
  sprintf(buf,"%1cR.Ayrenschmalz 2014" ,char(184));
  lcd.string (buf,false);
 
  // bit blit in a picture
//  lcd.gotoxy (40, 56);
//  lcd.blit (picture, sizeof picture);
  
  // draw a framed rectangle

  lcd.frameRect (10, 30, 30, 50,1,1);
  lcd.frameRect (12, 32, 28, 47,1,1);
  lcd.gotoxy (13,39);
  sprintf(buf,"75%1cC" ,char(248));
  lcd.string (buf,false);

  // draw a white diagonal line
  lcd.line (100, 4, 115, 30, 1);
  lcd.line (100, 8, 115, 34, 1);
  lcd.line (100, 4, 100, 8, 1);
  lcd.line (115,30, 115, 34, 1);
  
  lcd.frameRect (55, 20, 75, 50 ,1,1);
  lcd.gotoxy (56,39);
  lcd.string ("75%",false);
 
}  // end of setup

void loop () 
{}  // nothing to see here, move along



