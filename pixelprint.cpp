#include "pixelprint.h"

static void (*ppixelfunc)(int row, int column, bool state);

static int currentcolumn = 0;
static int charheight = 0;
static int charwidth = 0;
static int chargap = 0;
static byte* pbitmap = NULL;

void setcursor(int column) {
  currentcolumn = column;
}

void homecursor() {
  setcursor(0);
}

void setfont(const Font *font) {
  charheight = pgm_read_byte(&font->charheight);
  charwidth = pgm_read_byte(&font->charwidth);
  chargap = pgm_read_byte(&font->chargap);
  pbitmap = (byte*) pgm_read_word(&font->bitmap);
}

void setpixelfunc(void (*pixelfunc)(int row, int column, bool state)) {
  ppixelfunc = pixelfunc;
}

static byte getfontmask(char ch, byte row) {
  if (ch<' ' || ch>127) return 0;
  if (!pbitmap) return 0;
  byte offset = ch-' ';
  return pgm_read_byte(pbitmap+offset*charheight+row);
}

void writechar(char ch, int column) {
  if (column<0) column = currentcolumn;
  byte bitmask = 1<<(charwidth-1);
  for(int row=0; row<charheight; row++) {
    for(int bitcount=0; bitcount<charwidth; bitcount++) {
      bool isset = getfontmask(ch, row) & (bitmask >> bitcount);
      ppixelfunc(row, column+bitcount, isset);
    }
  }
  currentcolumn += charwidth+chargap;
}

void writetext(char* text, int column) {
  currentcolumn = column;
  while(char ch = *text++) {
    writechar(ch);
  }
}
