#pragma once

#include <avr/pgmspace.h>

typedef void (*commandfunc)();

struct commandtype {
	const char command;
	const char* help;
	commandfunc func; 
	};

typedef commandtype prog_commandtype PROGMEM;

void showcmds(const prog_commandtype* pCommands);
char runcmd(const char* title, const prog_commandtype* pCommands);
char runcmd_P(const char* title, const prog_commandtype* pCommands);
int getparam_int(byte position=1);
unsigned int getparam_uint(byte position=1);
char getparam_char(byte position = 1);
char* getparam_str();
void waitforkey(const char* message = nullptr);
