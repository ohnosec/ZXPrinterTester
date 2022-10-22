#pragma once

#include "font.h"

void setpixelfunc(void (*pixelfunc)(int row, int column, bool state));
void setfont(const Font *font);
void setcursor(int column);
void homecursor();

void writechar(char ch, int column = -1);
void writetext(char* text, int column = 0);
