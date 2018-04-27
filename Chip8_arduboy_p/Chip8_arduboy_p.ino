#include <Arduboy.h>
#include <stdlib.h>

Arduboy arduboy;
//INIT
unsigned short opcode;
unsigned short pc = 0x200;
unsigned short I = 0;
unsigned short sp = 0;

unsigned short stack[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char V[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const unsigned char memory[4096] PROGMEM = {240,144,144,144,240,32,96,32,32,112,240,16,240,128,240,240,16,240,16,240,144,144,240,16,16,240,128,240,16,240,240,128,240,144,240,240,16,32,64,64,240,144,240,144,240,240,144,240,16,240,240,144,240,144,144,224,144,224,144,224,240,128,128,128,240,224,144,144,144,224,240,128,240,128,240,240,128,240,128,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,110,5,101,0,107,6,106,0,163,12,218,177,122,4,58,64,18,8,123,1,59,18,18,6,108,32,109,31,163,16,220,209,34,246,96,0,97,0,163,18,208,17,112,8,163,14,208,17,96,64,240,21,240,7,48,0,18,52,198,15,103,30,104,1,105,255,163,14,214,113,163,16,220,209,96,4,224,161,124,254,96,6,224,161,124,2,96,63,140,2,220,209,163,14,214,113,134,132,135,148,96,63,134,2,97,31,135,18,71,31,18,172,70,0,104,1,70,63,104,255,71,0,105,1,214,113,63,1,18,170,71,31,18,170,96,5,128,117,63,0,18,170,96,1,240,24,128,96,97,252,128,18,163,12,208,113,96,254,137,3,34,246,117,1,34,246,69,192,19,24,18,70,105,255,128,96,128,197,63,1,18,202,97,2,128,21,63,1,18,224,128,21,63,1,18,238,128,21,63,1,18,232,96,32,240,24,163,14,126,255,128,224,128,4,97,0,208,17,62,0,18,48,18,222,120,255,72,254,104,255,18,238,120,1,72,2,104,1,96,4,240,24,105,255,18,112,163,20,245,51,242,101,241,41,99,55,100,0,211,69,115,5,242,41,211,69,0,238,240,0,128,0,252,0,170,0,0,0,0,0,110,5,0,224,18,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned char delay_timer = 0;
unsigned char sound_timer = 0;

unsigned char keys[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//For now these are constant length arrays of length 16! This means our mapping from editable index to RAM_memory will be (index % 16). 
int RAM_indices[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
unsigned char RAM_memory[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  // put your setup code here, to run once:

  arduboy.begin();
  Serial.begin(9600);
  arduboy.clear();

  arduboy.setFrameRate(15);

}

void emulateCycle(){
  /*Emulates cycle by decoding and executing opcode.
   * Note that any time we read from PROGMEM, we need to make sure the value we're grabbing hasn't been reassigned to RAM_memory.
   * We don't need to pass pointers in, we can edit arrays and counters in global space. 
   */
  unsigned short decoded = 0;
  unsigned short x = 0;
  unsigned short y = 0;

  
  bool dRAM_1 = false; //Will need to access RAM_memory for pc.
  bool dRAM_2 = false; //Will need to access RAM_memory for pc + 1.
  int pcind = 0;
  int pc1ind = 0;
  for(int i = 0; i < 16; i++){
    if(RAM_indices[i] == pc){ //pc is in dynamic memory.
      dRAM_1 = true;
      pcind = i;
    }
    if(RAM_indices[i] == pc + 1){ //pc + 1 is dynamic memory.
      dRAM_2 = true;
      pc1ind = i;
    }
  }

  unsigned char byte1;
  unsigned char byte2;
  if(dRAM_1 && dRAM_2){ //Both pc and pc + 1 are in dynamic memory.
    opcode = RAM_memory[pcind] << 8 | RAM_memory[pc1ind];
  }else if(dRAM_1){
    byte2 = pgm_read_word_near(memory + pc + 1);
    opcode = RAM_memory[pcind] << 8 | byte2;
  }else if(dRAM_2){
    byte1 = pgm_read_word_near(memory + pc);
    opcode = byte1 << 8 | RAM_memory[pc1ind];
  }else{ //Neither are in dynamic memory. MOST LIKELY CASE.
    
    byte1 = pgm_read_word_near(memory + pc); //Function for reading from PROGMEM
    byte2 = pgm_read_word_near(memory + pc + 1);
    opcode = byte1 << 8 | byte2;
  }

  decoded = opcode & 0xF000;

  x = (opcode & 0x0F00) >> 8;
  y = (opcode & 0x00F0) >> 4;

  //OPCODES AS REGULAR! SEE COMMENTS FOR CHANGES. FOR ORIGINAL SEE PYTHON FILE.
  if(decoded == 0x0000){
    if(opcode == 0x00E0){        
      arduboy.clear(); //Clears screen.
      pc += 2;
      
    }else if(opcode == 0x00EE){
      sp -= 1;
      pc = stack[sp];
      pc += 2;
    }
      
  }else if(decoded == 0x1000){
    pc = opcode & 0x0FFF;
      
  }else if(decoded == 0x2000){
    stack[sp] = pc;
    sp += 1;
    pc = opcode & 0x0FFF;
      
  }else if(decoded == 0x3000){
    if(V[x] == opcode & 0x00FF)
      pc += 4;
    else
      pc += 2;
        
  }else if (decoded == 0x4000){
    if(V[x] != opcode & 0x00FF)
      pc += 4;
    else
      pc += 2;
      
  }else if(decoded == 0x5000){
    if(V[x] == V[y])
      pc += 4;
    else
      pc += 2;
    
  }else if(decoded == 0x6000){
    V[x] = opcode & 0x00FF;
    pc += 2;  
    
  }else if(decoded == 0x7000){
    V[x] = V[x] + (opcode & 0x00FF);
    if((opcode & 0x00FF) > 255)
       V[15] = 1;
    else
       V[15] = 0;
       
    pc += 2;
       
  }else if(decoded == 0x8000){
    unsigned short last_digit = opcode & 0x000F;
    if(last_digit == 0x0){
      V[x] = V[y]; 
      pc += 2; 
    }else if(last_digit == 0x1){
      V[x] = V[x] | V[y];
      pc += 2;
    }else if(last_digit == 0x2){
      V[x] = V[x] & V[y];
      pc += 2;
    }else if(last_digit == 0x3){
      V[x] = V[x] ^ V[y];
      pc += 2;
    }else if(last_digit == 0x4){
      unsigned char s = V[x] + V[y];
      V[x] = V[x] + V[y];
      if(s > 255)
        V[15] = 1;
      else
        V[15] = 0;
      pc += 2;
    }else if(last_digit == 0x5){
      unsigned char diff = V[x] - V[y];
      V[x] = V[x] - V[y];
      if(diff < 0)
        V[15] = 0;
      else
        V[15] = 1;
      pc += 2;
    }else if(last_digit == 0x6){
      V[15] = V[x] & 0x1;
      V[x] = V[x] >> 1;
      pc += 2;
    }else if(last_digit == 0x7){
      unsigned char diff2 = V[y] - V[x];
      V[x] = V[y] - V[x];
      if(diff2 < 0)
        V[15] = 0;
      else
        V[15] = 1;
      pc += 2;
    }else if(last_digit == 0xE){
      V[15] = (V[x] & 0xC0) >> 6;
      V[x] = V[x] << 1;
      pc += 2;
    }
  
  }else if(decoded == 0x9000){
    if(V[x] != V[y])
      pc += 4;
    else
      pc += 2;
        
  }else if(decoded == 0xA000){
    I = opcode & 0x0FFF;
    pc += 2;  
  
  }else if(decoded == 0xB000){
    pc = (opcode & 0x0FFF) + V[0];  
    
  }else if(decoded == 0xC000){
    V[x] = (opcode & 0x00FF) & (rand() % 255); //RANDOM INTEGER 
    pc += 2;
    
  }else if(decoded == 0xD000){
    unsigned short heightl = opcode & 0x000F;
    Serial.println(opcode);
    unsigned short pixel = 0;

    V[15] = 0;
    
    for(int row = 0; row <= heightl; row++){
      for(int col = 0; col < 8; col++){
        
        bool dRAM_3 = false; //Pixel is taken from memory, so we need to check our RAM array!
        int pc2ind = 0;
        for(int i = 0; i < 16; i++){
          if(RAM_indices[i] == I + row)
            dRAM_3 = true;
            pc2ind = i;
        }

        if(dRAM_3)
          pixel = RAM_memory[pc2ind];
        else
          //pixel = memory[I + row];
          pixel = pgm_read_word_near(memory + I + row);
        Serial.println(I);
        Serial.println(row);
        Serial.println(pixel);
        Serial.println("-----------");
        if(pixel & (0x80 >> col) != 0){
          uint8_t pos1 = (V[x] + col) % 64;
          uint8_t pos2 = (V[y] + row) % 32;
          if(arduboy.getPixel(pos1, pos2)){ //This does evaluate to zero or 1...
            arduboy.drawPixel(pos1, pos2, BLACK); //Changes white to black...
            V[15] = 1; 
          }else
            arduboy.drawPixel(pos1, pos2, WHITE);
        }
        
        
      }
    }  

    pc += 2;
    
  }else if(decoded == 0xE000){
    unsigned short last_digit = opcode & 0x000F;
    if(last_digit == 0xE){
      if(keys[V[x]] == 1)
        pc += 4;
      else
        pc += 2;
          
    }else if(last_digit == 0x1){
      if(keys[V[x]] == 0)
        pc += 4;
      else
        pc += 2;
    }
    
  }else if(decoded == 0xF000){
    unsigned short last_digits = opcode & 0x00FF;
    if(last_digits == 0x07){
      V[x] = delay_timer;
      pc += 2;
        
    }else if(last_digits == 0x0A){
      bool key_press = false;
      for(int i = 0; i < 16; i++){
        if(keys[i] == 1){
          V[x] = i;
          key_press = true;  
        }  
      }

      if(key_press)
        pc += 2;
        
    }else if(last_digits == 0x15){
      delay_timer = V[x];
      pc += 2;  
      
    }else if(last_digits == 0x18){
      sound_timer = V[x];
      pc += 2; 
      
    }else if(last_digits == 0x1E){
      I = I + V[x];
      pc += 2; 
      
    }else if(last_digits == 0x29){
      I = V[x] * 5;
      pc += 2; 
      
    }else if(last_digits == 0x33){
      //Recall that we write modulo 16.
      RAM_memory[I % 16] = V[x] / 100;
      RAM_memory[(I + 1) % 16] = (V[x] / 10) % 10;
      RAM_memory[(I + 2) % 16] = (V[x] % 100) % 10;

      RAM_indices[I % 16] = I;
      RAM_indices[(I + 1) % 16] = I + 1;
      RAM_indices[(I + 2) % 16] = I + 2;

      pc += 2;
      
    }else if(last_digits == 0x55){
      //opcode not accessed in this case.
      for(int i = 0; i < 16; i++){
        if(i == x + 1)
          break;
      //writing to mem, forego for now- this opcode is not used for Brix.ch8.
      //we can quickly implement this in a similar fashion to the previous opcode.
      RAM_memory[(I + i) % 16] = V[i];
      RAM_indices[(I + i) % 16] = i;
      }

      pc += 2;
      
    }else if(last_digits == 0x65){
      for(int i = 0; i < 16; i++){
        if(i == x + 1)
          break;
        //Final memory read.
        if(I + i == RAM_indices[i])
          V[i] = RAM_memory[i];
        else
          V[i] = pgm_read_word_near(memory + I + i); 
      }  
      pc += 2;
    }
  }

  
  if(sound_timer > 0){
    sound_timer -=1 ;
    /*
    if(sound_timer == 0)
      BEEP
    */
  }

  if(delay_timer > 0)
    delay_timer -= 1;
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame()))
    return;
      
  arduboy.clear();
  arduboy.setCursor(1, 1);
  
  emulateCycle();
  arduboy.display();

}
