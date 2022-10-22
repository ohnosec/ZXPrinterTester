#pragma once

#include <Arduino.h>
#include "font.h"

const byte font7x5bitmaps[][7] PROGMEM = {
  { // 0x20   space
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x21   !
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000000,
    0b00000100,
  },
  { // 0x22   "
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x23   #
    0b00001010,
    0b00001010,
    0b00011111,
    0b00001010,
    0b00011111,
    0b00001010,
    0b00001010,
  },
  { // 0x24   $
    0b00000100,
    0b00001111,
    0b00010100,
    0b00001110,
    0b00000101,
    0b00011110,
    0b00000100,
  },
  { // 0x25   %
    0b00011100,
    0b00010101,
    0b00011010,
    0b00000100,
    0b00001011,
    0b00010101,
    0b00000111,
  },
  { // 0x26   &
    0b00001000,
    0b00010100,
    0b00010100,
    0b00001000,
    0b00010101,
    0b00010010,
    0b00001101,
  },
  { // 0x27   '
    0b00000110,
    0b00000110,
    0b00000010,
    0b00000100,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x28   (
    0b00000010,
    0b00000100,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00000100,
    0b00000010,
  },
  { // 0x29   )
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000100,
    0b00001000,
  },
  { // 0x2A   *
    0b00000100,
    0b00010101,
    0b00001110,
    0b00011111,
    0b00001110,
    0b00010101,
    0b00000100,
  },
  { // 0x2B   +
    0b00000000,
    0b00000100,
    0b00000100,
    0b00011111,
    0b00000100,
    0b00000100,
    0b00000000,
  },
  { // 0x2C   ,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00001100,
    0b00001100,
    0b00000100,
    0b00001000,
  },
  { // 0x2D   -
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011111,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x2E   .
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00001100,
    0b00001100,
  },
  { // 0x2F   /
    0b00000000,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00000000,
  },
  { // 0x30   0
    0b00001110,
    0b00010001,
    0b00010011,
    0b00010101,
    0b00011001,
    0b00010001,
    0b00001110,
  },
  { // 0x31   1
    0b00000100,
    0b00001100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00001110,
  },
  { // 0x32   2
    0b00001110,
    0b00010001,
    0b00000001,
    0b00001110,
    0b00010000,
    0b00010000,
    0b00011111,
  },
  { // 0x33   3
    0b00001110,
    0b00010001,
    0b00000001,
    0b00000110,
    0b00000001,
    0b00010001,
    0b00001110,
  },
  { // 0x34   4
    0b00000010,
    0b00000110,
    0b00001010,
    0b00010010,
    0b00011111,
    0b00000010,
    0b00000010,
  },
  { // 0x35   5
    0b00011111,
    0b00010000,
    0b00010000,
    0b00011110,
    0b00000001,
    0b00000001,
    0b00011110,
  },
  { // 0x36   6
    0b00000110,
    0b00001000,
    0b00010000,
    0b00011110,
    0b00010001,
    0b00010001,
    0b00001110,
  },
  { // 0x37   7
    0b00011111,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00001000,
    0b00001000,
  },
  { // 0x38   8
    0b00001110,
    0b00010001,
    0b00010001,
    0b00001110,
    0b00010001,
    0b00010001,
    0b00001110,
  },
  { // 0x39   9
    0b00001110,
    0b00010001,
    0b00010001,
    0b00001111,
    0b00000001,
    0b00000010,
    0b00001100,
  },
  { // 0x3A   :
    0b00000000,
    0b00001100,
    0b00001100,
    0b00000000,
    0b00001100,
    0b00001100,
    0b00000000,
  },
  { // 0x3B   ;
    0b00001100,
    0b00001100,
    0b00000000,
    0b00001100,
    0b00001100,
    0b00000100,
    0b00001000,
  },
  { // 0x3C   <
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
  },
  { // 0x3D   =
    0b00000000,
    0b00000000,
    0b00011111,
    0b00000000,
    0b00011111,
    0b00000000,
    0b00000000,
  },
  { // 0x3E   >
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
  },
  { // 0x3F   ?
    0b00001110,
    0b00010001,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00000000,
    0b00000100,
  },
  { // 0x40   @
    0b00001110,
    0b00010001,
    0b00000001,
    0b00001101,
    0b00010101,
    0b00010101,
    0b00001110,
  },
  { // 0x41   A
    0b00000100,
    0b00001010,
    0b00010001,
    0b00010001,
    0b00011111,
    0b00010001,
    0b00010001,
  },
  { // 0x42   B
    0b00011110,
    0b00001001,
    0b00001001,
    0b00001110,
    0b00001001,
    0b00001001,
    0b00011110,
  },
  { // 0x43   C
    0b00001110,
    0b00010001,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010001,
    0b00001110,
  },
  { // 0x44   D
    0b00011110,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00011110,
  },
  { // 0x45   E
    0b00011111,
    0b00010000,
    0b00010000,
    0b00011100,
    0b00010000,
    0b00010000,
    0b00011111,
  },
  { // 0x46   F
    0b00011111,
    0b00010000,
    0b00010000,
    0b00011100,
    0b00010000,
    0b00010000,
    0b00010000,
  },
  { // 0x47   G
    0b00001110,
    0b00010001,
    0b00010000,
    0b00010111,
    0b00010001,
    0b00010001,
    0b00001111,
  },
  { // 0x48   H
    0b00010001,
    0b00010001,
    0b00010001,
    0b00011111,
    0b00010001,
    0b00010001,
    0b00010001,
  },
  { // 0x49   I
    0b00001110,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00001110,
  },
  { // 0x4A   J
    0b00000111,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00010010,
    0b00001100,
  },
  { // 0x4B   K
    0b00010001,
    0b00010010,
    0b00010100,
    0b00011000,
    0b00010100,
    0b00010010,
    0b00010001,
  },
  { // 0x4C   L
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00011111,
  },
  { // 0x4D   M
    0b00010001,
    0b00011011,
    0b00010101,
    0b00010101,
    0b00010001,
    0b00010001,
    0b00010001,
  },
  { // 0x4E   N
    0b00010001,
    0b00011001,
    0b00010101,
    0b00010011,
    0b00010001,
    0b00010001,
    0b00010001,
  },
  { // 0x4F   O
    0b00001110,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00001110,
  },
  { // 0x50   P
    0b00011110,
    0b00010001,
    0b00010001,
    0b00011110,
    0b00010000,
    0b00010000,
    0b00010000,
  },
  { // 0x51   Q
    0b00001110,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010101,
    0b00010010,
    0b00001101,
  },
  { // 0x52   R
    0b00011110,
    0b00010001,
    0b00010001,
    0b00011110,
    0b00010100,
    0b00010010,
    0b00010001,
  },
  { // 0x53   S
    0b00001110,
    0b00010001,
    0b00010000,
    0b00001110,
    0b00000001,
    0b00010001,
    0b00001110,
  },
  { // 0x54   T
    0b00011111,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
  },
  { // 0x55   U
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00001110,
  },
  { // 0x56   V
    0b00010001,
    0b00010001,
    0b00010001,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00000100,
  },
  { // 0x57   W
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010101,
    0b00010101,
    0b00011011,
    0b00010001,
  },
  { // 0x58   X
    0b00010001,
    0b00010001,
    0b00001010,
    0b00000100,
    0b00001010,
    0b00010001,
    0b00010001,
  },
  { // 0x59   Y
    0b00010001,
    0b00010001,
    0b00001010,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
  },
  { // 0x5A   Z
    0b00011111,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b00011111,
  },
  { // 0x5B   [
    0b00001110,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001110,
  },
  { // 0x5C   \
    0b00000000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b00000001,
    0b00000000,
  },
  { // 0x5D   ]
    0b00001110,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00001110,
  },
  { // 0x5E   ^
    0b00000100,
    0b00001010,
    0b00010001,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x5F   _
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00011111,
  },
  { // 0x60   `
    0b00000110,
    0b00000110,
    0b00000100,
    0b00000010,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x61   a
    0b00000000,
    0b00000000,
    0b00001110,
    0b00000001,
    0b00001111,
    0b00010001,
    0b00001111,
  },
  { // 0x62   b
    0b00010000,
    0b00010000,
    0b00010110,
    0b00011001,
    0b00010001,
    0b00011001,
    0b00010110,
  },
  { // 0x63   c
    0b00000000,
    0b00000000,
    0b00000111,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00000111,
  },
  { // 0x64   d
    0b00000001,
    0b00000001,
    0b00001101,
    0b00010011,
    0b00010001,
    0b00010011,
    0b00001101,
  },
  { // 0x65   e
    0b00000000,
    0b00000000,
    0b00001110,
    0b00010001,
    0b00011111,
    0b00010000,
    0b00001110,
  },
  { // 0x66   f
    0b00000110,
    0b00001001,
    0b00001000,
    0b00011110,
    0b00001000,
    0b00001000,
    0b00001000,
  },
  { // 0x67   g
    0b00000000,
    0b00000000,
    0b00001111,
    0b00010001,
    0b00001111,
    0b00000001,
    0b00011110,
  },
  { // 0x68   h
    0b00010000,
    0b00010000,
    0b00010110,
    0b00011001,
    0b00010001,
    0b00010001,
    0b00010001,
  },
  { // 0x69   i
    0b00000100,
    0b00000000,
    0b00001100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00001110,
  },
  { // 0x6A   j
    0b00000010,
    0b00000000,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00010010,
    0b00001100,
  },
  { // 0x6B   k
    0b00001000,
    0b00001000,
    0b00001001,
    0b00001010,
    0b00001100,
    0b00001010,
    0b00001001,
  },
  { // 0x6C   l
    0b00001100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00001110,
  },
  { // 0x6D   m
    0b00000000,
    0b00000000,
    0b00011010,
    0b00010101,
    0b00010101,
    0b00010101,
    0b00010101,
  },
  { // 0x6E   n
    0b00000000,
    0b00000000,
    0b00010110,
    0b00011001,
    0b00010001,
    0b00010001,
    0b00010001,
  },
  { // 0x6F   o
    0b00000000,
    0b00000000,
    0b00001110,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00001110,
  },
  { // 0x70   p
    0b00000000,
    0b00000000,
    0b00011110,
    0b00010001,
    0b00011110,
    0b00010000,
    0b00010000,
  },
  { // 0x71   q
    0b00000000,
    0b00000000,
    0b00001111,
    0b00010001,
    0b00001111,
    0b00000001,
    0b00000001,
  },
  { // 0x72   r
    0b00000000,
    0b00000000,
    0b00010110,
    0b00011001,
    0b00010000,
    0b00010000,
    0b00010000,
  },
  { // 0x73   s
    0b00000000,
    0b00000000,
    0b00001111,
    0b00010000,
    0b00001110,
    0b00000001,
    0b00011110,
  },
  { // 0x74   t
    0b00000100,
    0b00000100,
    0b00001111,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000011,
  },
  { // 0x75   u
    0b00000000,
    0b00000000,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00010011,
    0b00001101,
  },
  { // 0x76   v
    0b00000000,
    0b00000000,
    0b00010001,
    0b00010001,
    0b00010001,
    0b00001010,
    0b00000100,
  },
  { // 0x77   w
    0b00000000,
    0b00000000,
    0b00010001,
    0b00010001,
    0b00010101,
    0b00010101,
    0b00001010,
  },
  { // 0x78   x
    0b00000000,
    0b00000000,
    0b00010001,
    0b00001010,
    0b00000100,
    0b00001010,
    0b00010001,
  },
  { // 0x79   y
    0b00000000,
    0b00000000,
    0b00010001,
    0b00010001,
    0b00001111,
    0b00000001,
    0b00001110,
  },
  { // 0x7A   z
    0b00000000,
    0b00000000,
    0b00011111,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00011111,
  },
  { // 0x7B   {
    0b00000010,
    0b00000100,
    0b00000100,
    0b00001000,
    0b00000100,
    0b00000100,
    0b00000010,
  },
  { // 0x7C   |
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000000,
    0b00000100,
    0b00000100,
    0b00000100,
  },
  { // 0x7D   }
    0b00001000,
    0b00000100,
    0b00000100,
    0b00000010,
    0b00000100,
    0b00000100,
    0b00001000,
  },
  { // 0x7E   ~
    0b00001000,
    0b00010101,
    0b00000010,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
  },
  { // 0x7F   del
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
  },
};

const Font font7x5 PROGMEM = {7, 5, 2, (byte*) font7x5bitmaps};
