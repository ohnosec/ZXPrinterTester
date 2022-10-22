#include "menu.h"
#include "print.h"
#include "pixelbuffer.h"
#include "digitalWriteFast.h"
#include "font.h"

const char menuPrinterStatus[] PROGMEM    = "Printer status";
const char menuPrinterMotorOn[] PROGMEM   = "Printer motor on";
const char menuPrinterMotorOff[] PROGMEM  = "Printer motor off";
const char menuPrintBuffer[] PROGMEM      = "Print buffer";

const char menuWriteAlphabet[] PROGMEM    = "Write alphabet";
const char menuWriteBlocks[] PROGMEM      = "Write blocks";
const char menuWriteFox[] PROGMEM         = "Write quick fox";
const char menuWriteHello[] PROGMEM       = "Write hello";
const char menuWriteMessage[] PROGMEM     = "Write message";

void cmdPrinterStatus();
void cmdPrinterMotorOn();
void cmdPrinterMotorOff();
void cmdPrintBuffer();

void cmdWriteAlphabet();
void cmdWriteBlocks();
void cmdWriteFox();
void cmdWriteHello();
void cmdWriteMessage();

const char title[] PROGMEM = "ZX printer tester";

const prog_commandtype commands[] PROGMEM = {
  { 'O', menuPrinterMotorOff, cmdPrinterMotorOff },
  { 'N', menuPrinterMotorOn,  cmdPrinterMotorOn },
  { 'S', menuPrinterStatus, cmdPrinterStatus },
  { 'P', menuPrintBuffer, cmdPrintBuffer },
  { 'A', menuWriteAlphabet, cmdWriteAlphabet },
  { 'B', menuWriteBlocks, cmdWriteBlocks },
  { 'F', menuWriteFox, cmdWriteFox },
  { 'H', menuWriteHello, cmdWriteHello },
  { 'M', menuWriteMessage, cmdWriteMessage },
  { '\0' } // DONT REMOVE THIS "END OF MENU" MARKER
};

/*
Port FBh Read - Printer Status
  Bit  Expl.
  0    Data Request   (0=Busy, 1=Ready/DRQ)
  1-5  Not used
  6    Printer Detect (0=Okay, 1=None)
  7    Newline        (0=Nope, 1=Begin of new line)
Port FBh Write - Printer Output
  Bit  Expl.
  0    Not used
  1    Undoc/Speed?   (0=Normal, 1=used to slow-down last 2 scanlines)
  2    Motor          (0=Start, 1=Stop)
  3-6  Not used
  7    Pixel Output   (0=White/Silver, 1=Black)
*/
namespace Bus {
#if defined(__AVR_ATmega2560__)
  const int A2 = 21;
  const int A7 = 28;

  const int WR = 36;
  const int RD = 37;
  const int IORQ = 38;

  const int D0 = 49;
  const int D1 = 48;
  const int D2 = 47;
  const int D3 = 44;
  const int D4 = 43;
  const int D5 = 45;
  const int D6 = 46;
  const int D7 = A13;
#elif defined(__AVR_ATmega328P__) 
  const int A2 = A0;
  const int A7 = A1;

  const int WR = 12;
  const int RD = 11;
  const int IORQ = 10;

  const int D0 = 2;
  const int D1 = 3;
  const int D2 = 4;
  const int D3 = 5;
  const int D4 = 6;
  const int D5 = 7;
  const int D6 = 8;
  const int D7 = 9;
#else
  #error Unsupported board
#endif
}

// Read data
const byte IN_PRINTER_READY = Bus::D0;
const byte IN_PRINTER_NOT_DETECTED = Bus::D6;
const byte IN_PRINTER_ON_PAPER = Bus::D7;

// Write data
const byte OUT_PRINTER_MOTOR_SLOW = Bus::D1;
const byte OUT_PRINTER_MOTOR_OFF = Bus::D2;
const byte OUT_PRINTER_PIXEL_ON = Bus::D7;

void writetext(char* text, int column = 0);

void setup() {
  Serial.begin(9600);

  digitalWriteFast(Bus::A2, LOW);
  digitalWriteFast(Bus::A7, HIGH);
  digitalWriteFast(Bus::WR, HIGH);
  digitalWriteFast(Bus::RD, HIGH);
  digitalWriteFast(Bus::IORQ, LOW);

  pinModeFast(Bus::A2, OUTPUT);
  pinModeFast(Bus::A7, OUTPUT);
  pinModeFast(Bus::WR, OUTPUT);
  pinModeFast(Bus::RD, OUTPUT);
  pinModeFast(Bus::IORQ, OUTPUT);

  digitalWriteFast(IN_PRINTER_READY, LOW);
  digitalWriteFast(IN_PRINTER_NOT_DETECTED, LOW);
  digitalWriteFast(IN_PRINTER_ON_PAPER, LOW);
  digitalWriteFast(OUT_PRINTER_MOTOR_SLOW, HIGH);
  digitalWriteFast(OUT_PRINTER_MOTOR_OFF, HIGH);

  pinModeFast(IN_PRINTER_READY, INPUT);
  pinModeFast(IN_PRINTER_NOT_DETECTED, INPUT);
  pinModeFast(IN_PRINTER_ON_PAPER, INPUT);
  pinModeFast(OUT_PRINTER_MOTOR_SLOW, OUTPUT);
  pinModeFast(OUT_PRINTER_MOTOR_OFF, OUTPUT);

  clearpixels();
}

void loop() {
  runcmd_P(title, commands);
}

void writechar(char ch, int column) {
  byte bitmask = 1<<(charwidth-1);
  for(int row=0; row<charheight; row++) {
    for(int bitcount=0; bitcount<charwidth; bitcount++) {
      bool isset = getfontmask(ch, row) & (bitmask >> bitcount);
      setpixel(row, column+bitcount, isset);
    }
  }
}

void writetext(char* text, int column = 0) {
  while(char ch = *text++) {
    writechar(ch, column);
    column += charwidth+2;
  }
}

void plotsquares() {
  for(int row=0; row<rows; row++) {
    bool pixel = false;
    for (byte column = 0; column < columns-8; column++) {
      if ((column % 8) == 0) pixel = !pixel;
      setpixel(row, column, pixel);
    }
  }
}

inline void readon() {
  digitalWriteFast(Bus::RD, LOW);
}

inline void readoff() {
  digitalWriteFast(Bus::RD, HIGH);
}

inline void writeon() {
  digitalWriteFast(Bus::WR, LOW);
}

inline void writeoff() {
  digitalWriteFast(Bus::WR, HIGH);
}

inline void readtoggle() {
  readon();
  readoff();
}

inline void writetoggle() {
  writeon();
  writeoff();
}

inline void outpixel(bool ison) {
  if(ison) { 
    digitalWriteFast(OUT_PRINTER_PIXEL_ON, HIGH);
  } else {
    digitalWriteFast(OUT_PRINTER_PIXEL_ON, LOW);
  }
  _delay_us(2); // needs to be stable for a couple of microseconds, not sure why
  pinModeFast(OUT_PRINTER_PIXEL_ON, OUTPUT);
  writetoggle();
  pinModeFast(OUT_PRINTER_PIXEL_ON, INPUT);
  digitalWriteFast(OUT_PRINTER_PIXEL_ON, LOW);
}

inline bool isready() {
  readon();
  bool value = digitalReadFast(IN_PRINTER_READY)==HIGH;
  readoff();
  return value;
}

inline bool isconnected() {
  readon();
  bool value = digitalReadFast(IN_PRINTER_NOT_DETECTED)==LOW;
  readoff();
  return value;
}

inline bool isonpaper() {
  readon();
  bool value = digitalReadFast(IN_PRINTER_ON_PAPER)==HIGH;
  readoff();
  return value;
}

inline void waitforpaper() {
  outpixel(false); // paper detect doesn't work while stylus is on
  while(!isonpaper());
}

inline void waitfornopaper() {
  outpixel(false); // paper detect doesn't work while stylus is on
  while(isonpaper());
}

inline void motoron() {
  digitalWriteFast(OUT_PRINTER_MOTOR_OFF, LOW);
  writetoggle();
}

inline void motoroff() {
  digitalWriteFast(OUT_PRINTER_MOTOR_OFF, HIGH);
  writetoggle();
}

inline void motorslow() {
  digitalWriteFast(OUT_PRINTER_MOTOR_SLOW, HIGH);
  writetoggle();
}

inline void motorfast() {
  digitalWriteFast(OUT_PRINTER_MOTOR_SLOW, LOW);
  writetoggle();
}

void printpixels() {
  outpixel(false);
  if (!isconnected()) {
    print_P(PSTR("No printer detected\r\n"));
    return;
  }
  motoron();
  motorslow();
  //TODO: we should start out fast and slow down for the last two lines
  //motorfast(); 
  waitfornopaper();
  seekpixel();
  for (byte row = 0; row < rows; row++) {
    waitforpaper();
    bool pixelon = false;
    for (byte column = 0; column < columns-1; column++) {
      outpixel(pixelon);
      pixelon = readpixel();
      while(!isready());
      outpixel(pixelon);
     }
    skippixel(1);
    outpixel(false);
  }
  readtoggle();
  motoroff();
}

void cmdPrinterStatus() {
  outpixel(false); // reset latches

  print_P(PSTR("Ready="));
  if (isready()) print_P(PSTR("TRUE"));
  else print_P(PSTR("FALSE"));
  println();

  print_P(PSTR("Connected="));
  if (isconnected()) print_P(PSTR("TRUE"));
  else print_P(PSTR("FALSE"));
  println();

  print_P(PSTR("On paper="));
  if (isonpaper()) print_P(PSTR("TRUE"));
  else print_P(PSTR("FALSE"));
  println();
}

void cmdPrinterMotorOn() {
  print_P(PSTR("Motor on"));
  motoron();
}

void cmdPrinterMotorOff() {
  print_P(PSTR("Motor off"));
  motoroff();
}

void cmdPrintBuffer() {
  print_P(PSTR("Printing buffer\r\n"));
  printpixels();
  print_P(PSTR("Done\r\n"));
}

void cmdWriteAlphabet() {
  clearpixels();

  int column=0;
  for(char ch='A'; ch<='Z'; ch++) {
    writechar(ch, column);
    column += charwidth+2;
  }

  printpixels();
}

void cmdWriteBlocks() {
  clearpixels();
  plotsquares();
  
  printpixels();
}

void cmdWriteFox() {
  clearpixels();
  writetext("The quick brown fox jumps over");
  
  printpixels();
}

void cmdWriteHello() {
  clearpixels();
  writetext("Hello world!");
  
  printpixels();
}

void cmdWriteMessage() {
  char* message = getparam_str();
  clearpixels();
  writetext(message);
  
  printpixels();
}
