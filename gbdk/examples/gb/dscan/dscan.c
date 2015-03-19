/*+------------------------------------------------------+*/
/*|This file is quickly going to become a clusterfuck,   |*/
/*|so rev up that ctrl+f!                                |*/
/*|Scroll right down to the bottom for Main().           |*/
/*+------------------------------------------------------+*/

/*includes*/
#include <gb/gb.h>
#include <stdlib.h>
#include <rand.h>
#include <gb/console.h>
#include <stdio.h>
#include <string.h>

/* bitmaps */
#include "bkg.h"
#include "bkg.c"
#include "bkg_m.c"
#include "bkg_c.c"
#include "fore.h"
#include "fore.c"

/*-----MESSAGE-SYSTEM-----*/
char message[15];

void writemessage()
{
	gotoxy(1, 16);
	printf("%s\n", message);
}

/*---------DRAWS GAME AREA---------*/
void setupscreen()
{
	int x,y;

	for(y=0;y<16;y++)
	{
		for(x=0;x<19;x++)
		{
			gotoxy(x,y);
			
			if(x==0 || x==18)
			{
				printf("|");
			}
			else
			{
				printf(".");
			}
		}
		
		printf("\n");
	}
	
	gotoxy(0,0);
	printf("+-----------------+");
	
	gotoxy(0,15);
	printf("+-----------------+");
}

/*----------------------MAIN-------------------------*/
/*---------------------PROGRAM-----------------------*/
void main()
{
	setupscreen();
	strcpy(message, "Hello World");
	writemessage();
	waitpad(J_START);
	strcpy(message, "sfgsdfg");
	writemessage();
	//printf("NIGGERS");
}
