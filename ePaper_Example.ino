#include "ePaper.h"  // This file includes defines for each displayable character


int EIOpin = 8;     // Input/output pin for chip selection
int XCKpin = 9;     // Clock input pin for taking display data
int LATCHpin = 10;   // Latch pulse input pin for display data
int SLEEPBpin = 11;  // Sleep Pin for the display
int DI0pin = 12;     // Input pin for display data

//setup display with pin definitions
ePaper epaper = ePaper(EIOpin, XCKpin, LATCHpin, SLEEPBpin, DI0pin);


void setup(){
  Serial.begin(9600);
  
  epaper.writeTop("Random");
  epaper.writeBottom("Numbers");
  epaper.writeDisplay();
  
  delay(5000);
  
}

void loop(){

	
  long top = random(2147483646);
  long bottom = random(2147483646);
  
  
  epaper.writeNumberTop(top);
  epaper.writeNumberBottom(bottom);
  epaper.writeDisplay();
	
  delay(5000);
    
  
  
}