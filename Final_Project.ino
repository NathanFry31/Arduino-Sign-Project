//Web Link for Library
//https://github.com/wayoda/LedControl
//Libray For LED Matrix
#include <LedControl.h>

//This is the Pin Output
int DIN = 12; //Pin 12 to Data In
int CS =  11; //Pin 11 to Chip Set
int CLK = 10; //Pin 10 to Clock
int maxInUse = 1;//Number Of Led Matrixs
int waitTime =500;//Wait Time Between character

// English Alphabet In Matrix 8*8 in Alphabetical Order. All Capital
byte a[8]= {0x18,0x3C,0x66,0x66,0xFF,0xC3,0xC3,0xC3,};
byte b[8]= {0x7E,0x61,0x61,0x7E,0x7E,0x61,0x61,0x7E,}; 
byte c[8]= {0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,}; 
byte d[8]= {0x7C,0x6E,0x63,0x63,0x63,0x63,0x6E,0x7C,}; 
byte e[8]= {0xFF,0xFF,0xC0,0xFC,0xFC,0xC0,0xFF,0xFF,};
byte f[8]= {0xFF,0xFF,0xC0,0xFC,0xFC,0xC0,0xC0,0xC0,};
byte g[8]= {0xFF,0xFF,0xC0,0xC0,0xCF,0xC3,0xFF,0xFF,};
byte h[8]= {0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66,};
byte i[8]= {0x3C,0x3C,0x18,0x18,0x18,0x18,0x3C,0x3C,};
byte j[8]= {0xFF,0x18,0x18,0x18,0x18,0x18,0xF8,0xF8,};
byte k[8]= {0xC3,0xC6,0xDE,0xF8,0xF8,0xF8,0xDE,0xC7,};
byte l[8]= {0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x7E,};
byte m[8]= {0xC3,0xE7,0xFF,0xDB,0xDB,0xDB,0xDB,0xDB,};
byte n[8]= {0xE3,0xF3,0xF3,0xDB,0xDB,0xCF,0xC7,0xC3,};
byte o[8]= {0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E,};
byte p[8]= {0x7E,0x62,0x62,0x62,0x7E,0x60,0x60,0x60,};
byte q[8]= {0x7C,0x82,0x82,0x82,0x82,0x8A,0x86,0x7E,};
byte r[8]= {0xFF,0xC1,0xC1,0xFF,0xF8,0xD8,0xDC,0xCC,};
byte s[8]= {0xFF,0xFF,0xC0,0xFF,0xFF,0x03,0xFF,0xFF,};
byte t[8]= {0xFF,0xFF,0x18,0x18,0x18,0x18,0x18,0x18,};
byte u[8]= {0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF,};
byte v[8]= {0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x3C,0x18,};
byte w[8]= {0xC3,0xC3,0xDB,0xDB,0xDB,0xFF,0x7E,0x00,};
byte x[8]= {0xC3,0xC3,0xE7,0x7C,0x18,0xFF,0xC3,0xC3,};
byte y[8]= {0x66,0x66,0x66,0x3C,0x18,0x18,0x18,0x3C,};
byte z[8]= {0xFF,0xC3,0x86,0x0C,0x18,0x31,0x63,0xFF,};

//Number 0-9 for Matrix in Numeric Order
byte zero[8]= {0x7E,0x46,0x4E,0x5E,0x7A,0x72,0x62,0x7E,};
byte one[8]= {0x38,0x78,0x18,0x18,0x18,0x18,0x18,0xFF,};
byte two[8]= {0x7E,0xC3,0x03,0x3E,0x60,0xC0,0xC3,0xFF,};
byte three[8]= {0x3E,0xC3,0x03,0x02,0x3E,0x02,0xC3,0x7F,};
byte four[8]= {0xC6,0xC6,0xC6,0xFE,0xFE,0x06,0x06,0x06,};
byte five[8]= {0xFF,0xC0,0xFE,0x03,0x03,0x03,0xC3,0x7E,};
byte six[8]= {0x3E,0x60,0xC0,0xF8,0x8C,0x8C,0xCC,0x78,};
byte seven[8]= {0x7F,0x63,0x03,0x03,0x03,0x06,0x06,0x06,};
byte eight[8]= {0x3C,0x42,0x42,0x7E,0x7E,0x42,0x42,0x3C,};
byte nine[8]= {0x3F,0x43,0x43,0x43,0x3F,0x03,0x03,0x03,};

//special characters like periods or commas
byte period[8]= {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,}; //.
byte comma[8]= {0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x18,}; //,
byte apostrophe[8] = {0x60,0x60,0xC0,0x00,0x00,0x00,0x00,0x00,};//'
byte Epoint[8]= {0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,};//!
byte happyFace[8]= {0x7E,0x81,0xA5,0x81,0xC3,0xA5,0x99,0x7E,};//:)
LedControl lc=LedControl(DIN,CLK,CS,0);

// Arduino Setup
void setup(){
 lc.shutdown(0,false);       //power-saving mode on startup
 lc.setIntensity(0,1);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}

// Passing happyHoildays
void loop(){ 
    happyHoildays();
}
//Loop that would print the Word Happy Hoilday's with a smile
void happyHoildays()
{
  printByte(h);//Calls up the letter H and prints it to the matrix
  delay(waitTime);//delays the next letter by 0.05 seconds
  printByte(a);
  delay(waitTime);
  printByte(p);
  delay(waitTime);
  lc.clearDisplay(0);//This is here because of the back to back P's. This is to show some seperation.
  delay(waitTime); 
  printByte(p);
  delay(waitTime);
  printByte(y);
  delay(waitTime);
  printByte(h);
  delay(waitTime);
  printByte(o);
  delay(waitTime);
  printByte(l);
  delay(waitTime);
  printByte(i);
  delay(waitTime);
  printByte(d);
  delay(waitTime);
  printByte(a);
  delay(waitTime);
  printByte(y);
  delay(waitTime);
  printByte(apostrophe);
  delay(waitTime);
  printByte(s);
  delay(waitTime);
  printByte(Epoint);
  delay(waitTime);
  printByte(happyFace);//The Happy face
  delay(2000);
}

//Sets Row for the Matrix
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
