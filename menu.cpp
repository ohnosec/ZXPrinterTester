#include "Arduino.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <util/delay.h>
#include "menu.h"
#include "print.h"

static char cmdline[80];

char readch() {
    while(!Serial.available());
    return Serial.read();
    }

void showcmds(const prog_commandtype* pCommands) {
    for(const prog_commandtype *cmds = pCommands; ; ++cmds) {
        char ch = pgm_read_byte(&cmds->command);
        if (ch=='\0') break;
        const char* help = (char*) pgm_read_word(&cmds->help);
        print("  ");
        print(ch);
        print(")  "); 
        for(char helpch; (helpch = pgm_read_byte(help++))!=0; ) {
            print(helpch);
            }
        println();
        }
    }


void readcmdline() {
    memset(cmdline, 0, sizeof(cmdline));
    int i = 0;
    while(i < (int) sizeof(cmdline)-1) {
        char c = readch();
        switch(c) {
            case '\r': case '\n': 
                print("\r\n");
                return;
            case '\b': case 127:
                if (i>0) {
                    --i;
                    print("\b \b");
                    }
                cmdline[i] = '\0';
                break;
            default:
                if (c>=' ') {
                    cmdline[i++] = c;
                    print(c);
                }
                break;
            }
        }
    print('\n');
    }

char* getcmd() {
    readcmdline();
    char* line = cmdline;
    while(*line && isspace(*line)) ++line;
    return line;
    }

char* getcmd(const char* prompt) {
    print(prompt);
    return getcmd();
    }

char* getcmd_P(const char* prompt) {
    print_P(prompt);
    return getcmd();
    }

void clearscreen() {
    print(  
        "\x1b[2J"  // clear screen
        "\x1b[H"   // home
        );
    }

char runcmd(const prog_commandtype* pCommands) {
    showcmds(pCommands);
    println();
    char* line = getcmd_P(PSTR("Select an option> "));    
    char cmd = toupper(line[0]);
    if (cmd == '\0') return '\0';
    if (line[1]!='\0' && !isspace(line[1])) cmd = '\0';
    for(const prog_commandtype *cmds = pCommands; ; ++cmds) {
        char ch = pgm_read_byte(&cmds->command);
        if (ch=='\0') {
            println();
            print_P(PSTR("Unknown command!"));
            println();
            readch();
            println();
            break;
            }
        if (cmd==ch) {
            println();
            commandfunc func = (commandfunc) pgm_read_word(&cmds->func);
            if (func) func();
            println();
            print_P(PSTR("Press any key to continue..."));
            readch();
            println();
            break;
            }
        }
    return cmd;
    }

char runcmd(const char* title, const prog_commandtype* pCommands) {
    clearscreen();
    println();
    print(title);
    println();
    println();
    return runcmd(pCommands);
}

char runcmd_P(const char* title, const prog_commandtype* pCommands) {
    clearscreen();
    println();
    print_P(title);
    println();
    println();
    return runcmd(pCommands);
}

char* gettoken(byte position) {
    char* line = cmdline;
    for(byte pos = 0; pos<position; pos++) {
      while(*line && isspace(*line)) ++line;
      while(*line && !isspace(*line)) ++line;
    }
    while(*line && isspace(*line)) ++line;
    return line;
}

unsigned int atoui(char* p) {
  unsigned int val = 0;
  bool hasval = false;
  while(isspace(*p)) ++p;
  while(isdigit(*p)) { 
    hasval = true; 
    val = val*10 + (*p++ - '0');
  }
  return hasval ? val : -1;
}

unsigned int getparam_uint(byte position = 1) {
    char* param = gettoken(position);
    return atoui(param);
}

int getparam_int(byte position = 1) {
    char* param = gettoken(position);
    return atoi(param);
}

char getparam_char(byte position = 1) {
  char* param = gettoken(position);
  return *param;
}

char* getparam_str() {
  char* line = cmdline;

  while(*line && isspace(*line)) ++line;
  while(*line && !isspace(*line)) ++line;
  while(*line && isspace(*line)) ++line;

  return line;
}

void waitforkey(const char* message = nullptr) {
  if(message) Serial.print(message);
  else Serial.print("\r\npress a key...");
  while(!Serial.available());
  while(Serial.available()) Serial.read();
  Serial.println();
}
