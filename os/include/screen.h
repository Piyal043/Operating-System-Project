#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"

int cursorX=0, cursorY=0;
const uint8 sw=80, sh=25, sd=2;    //we define the screen width,height and depth sw=no. of column sh=no. of rows  sd= two space, one for char and other for color


void clearLine(uint8 from,uint8 to)
{
	uint16 i=sw* from * sd;
	string vidmem=(string)0xb8000;
	for(i;i<(sw*(to+1)*sd);i++)
	{
		vidmem[i]=0x0;
	}
}
void updateCursor()
{
	unsigned temp;
	temp = cursorY * sw + cursorX;
	outportb(0x3D4,14);		//CRT control register: select cursor location
	outportb(0x3D5, temp >> 8);     // send the high byte across the bus
	outportb(0x3D4, 15);		//crt control register: select send low byte
	outportb(0x3D5, temp);		//send the low byte of the cursor location
}
void clearScreen()
{
	clearLine(0,sh-1);
	cursorX=0;
	cursorY=0;
	updateCursor();
} 
void scrollUp(uint8 lineNumber)
{
	string vidmem = (string) 0xb8000;
	uint16 i=0;
	for(i; i<sw*(sh-1)*sd;i++)
	{
		vidmem[i]=vidmem[i+sw*sd*lineNumber];
	}
	clearLine(sh-1-lineNumber,sh-1);
	if((cursorY - lineNumber) < 0)
	{
		cursorY=0;
		cursorX=0;
	}
	else
	{
		cursorY -= lineNumber;
	}
	updateCursor();
}

void newLineCheck( )
{
	if(cursorY >=sh-1)
	{
		scrollUp(1);
	}
}

void printch(char c)
{
	string vidmem=(string) 0xb8000;
	switch(c)
	{
		case (0x08) :
							if(cursorX  > 0 )
							{
								cursorX-- ;
								vidmem[(cursorY * sw + cursorX)*sd ]=0x00;
							}
							break;
		case (0x09) :
							cursorX= ( cursorX + 8 ) & ~( 8 -1);
							break;
		case ( '\r') :
							cursorX=0;
							break;
		case ( '\n' ) :
							cursorX=0;
							cursorY++;
							break;
		default:
							vidmem [ ( (cursorY * sw  + cursorX)) *sd] =c;
							vidmem [ ( (cursorY * sw  + cursorX)) *sd +1]=0x0F;
							cursorX++;
							break;
	}
	if(cursorX >= sw)
	{
		cursorX=0;
		cursorY++;
	}
	//newlineCheck();
	updateCursor();
}
void print (string ch)
{
	uint16 i=0;
	uint8 length = strlength(ch);
	for(i;i<length;i++)
	{
		printch(ch[i]);
	}
}

#endif

