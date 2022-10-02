#pragma once

const int rows = 8;
const int columns = 256;

extern byte pixels[rows*(columns/8)];

void setpixel(int row, int column, bool state);
void clearpixels();

void seekpixel(int row = 0, int column = 0);
void nextpixel();
bool readpixel();
void skippixel(int count);
