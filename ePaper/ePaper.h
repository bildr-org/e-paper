#ifndef ePaper_h
#define ePaper_h


// Include the standard types
#include <Arduino.h>

// Define the Shifter class
class ePaper
{
  public:
    // Constructor
    
     ePaper(int EIO1pin, int XCKpin, int LATCHpin, int SLEEPBpin, int DI0pin);
   	
  	void writeDisplay();
  	void writeBottom(char * characterData);
  	void writeTop(char * characterData);
  	void writeNumberBottom(long input);
  	void writeNumberTop(long input);
  	
	



  private:
  	void clock();
  	void latch();
  	void print(char * displayTop, char * displayBottom, int bw, int com);
   	void flipData(char * characterData);
  	void createData(char * characterData, char * toDisplay);

  	char topData[160];
	char bottomData[160];
	char bottomInput[10];
  
  	int _EIO;
  	int _XCK;
  	int _LATCH;
  	int _SLPB;
  	int _DI0;
  	

  	
  	
  
};

#endif //Shifter_h