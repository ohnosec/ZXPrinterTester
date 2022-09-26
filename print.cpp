#include "Arduino.h"
#include <stdlib.h>
#include "print.h"
#include <avr/pgmspace.h>

void print(const char ch) {
  Serial.write(ch);
}

void print(const char* str) {
  while(*str) print(*str++);
}

void print(const int val) {
  char str[20];
  itoa(val, str, 10);
  print(str);
}

void printhex(const int val) {
  char str[20];
  itoa(val, str, 16);
  print(str);
}

void print(const bool val) {
  print(val ? "true" : "false");
}

void print(const unsigned int val) {
  char str[20];
  utoa(val, str, 10);
  print(str);
}

void printhex(const unsigned int val) {
  char str[20];
  utoa(val, str, 16);
  print(str);
}

void println() {
  print("\r\n");
}

void print_P(const char *str) {
  char ch;
  while((ch = pgm_read_byte(str++)) != 0) {
    print(ch);
  }
}
