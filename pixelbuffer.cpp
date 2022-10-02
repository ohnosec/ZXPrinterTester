#include <Arduino.h>
#include "pixelbuffer.h"

byte pixels[rows*(columns/8)] = {};

static byte* pixelptr = (byte*) pixels;
static byte pixelmask = 0x80;

inline byte makeindex(int row, int column) __attribute__((always_inline));
inline byte makemask(int column) __attribute__((always_inline));

static inline byte makeindex(int row, int column) {
  return row*(columns/8)+column/8;
}

static inline byte makemask(int column) {
  return 0x80>>(column&7);
}

void setpixel(int row, int column, bool state) {
  byte index = makeindex(row, column);
  byte mask = makemask(column);
  if (state)
    pixels[index] |= mask;
  else
    pixels[index] &= ~mask;
}

void clearpixels() {
  for(int row=0; row<rows; row++) {
    for (byte column = 0; column < columns-8; column++) {
      setpixel(row, column, false);
    }
  }
}

void seekpixel(int row = 0, int column = 0) {
  pixelptr = (byte*)pixels+makeindex(row, column);
  pixelmask = makemask(column);
}

void nextpixel() {
  pixelmask >>= 1;
  if(!pixelmask) {
    pixelmask = 0x80;
    ++pixelptr;
  }
}

void skippixel(int count) {
  while(count--) nextpixel();
}

bool readpixel() {
  bool isset = *pixelptr & pixelmask;
  nextpixel();
  return isset;
}
