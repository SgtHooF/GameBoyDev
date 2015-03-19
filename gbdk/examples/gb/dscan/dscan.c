/*+------------------------------------------------------+*/
/*|This file is quickly going to become a clusterfuck,   |*/
/*|so rev up that ctrl+f!                                |*/
/*|Scroll right down to the bottom for Main().           |*/
/*+------------------------------------------------------+*/

/*Good Chars for Later:
		1->4 = the arrow keys
		5 = box
*/

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

/*things for the player*/
char player_icon;
UINT8 player_oldX;
UINT8 player_oldY;
UINT8 player_newX;
UINT8 player_newY;

/*things for the game*/
int key;

/*-----MESSAGE-SYSTEM-----*/
char message[15];

void writemessage()
{
	gotoxy(0,16);
	printf(">~-~-~-~-~-~-~-~-~<");

	gotoxy(2, 16);
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

/*draws player at new location, and floor at the old*/
void drawplayer()
{
	gotoxy(player_oldX, player_oldY);
	printf(".");
	gotoxy(player_newX, player_newY);
	printf("%c", player_icon);
}

/*updates the players position based on joypad*/
void updateplayer()
{
	key=joypad();
	
	player_oldX = player_newX;
	player_oldY = player_newY;
	
	if(key & J_LEFT)
	{
		if(player_oldX > 1)
		{
			player_newX=(player_oldX-1);
		}
	}
	
	if(key & J_RIGHT)
	{
		if(player_oldX < 17)
		{
			player_newX=(player_oldX+1);
		}
	}
	
	if(key & J_UP)
	{
		if(player_oldY > 1)
		{
			player_newY=(player_oldY-1);
		}
	}
	
	if(key & J_DOWN)
	{
		if(player_oldY < 14)
		{
			player_newY=(player_oldY+1);
		}
	}
	
	/*Additional test input logic*/
	if(key & J_A)
	{
		strcpy(message, "Pressed A");
		writemessage();
	}
	
	if(key & J_B)
	{
		strcpy(message, "Pressed B");
		writemessage();
	}
	
	if(key & J_START)
	{
		strcpy(message, "Pressed START");
		writemessage();
	}
	
	if(key & J_SELECT)
	{
		strcpy(message, "Pressed SELECT");
		writemessage();
	}
}

/*----------------------MAIN-------------------------*/
/*---------------------PROGRAM-----------------------*/
void main()
{
	/*initialize player attributes*/
	strcpy(message, "Init Player");
	writemessage();
	player_icon = 'P';
	player_oldX = 5;
	player_oldY = 5;
	player_newX = 5;
	player_newY = 5;
	
	/*initialize world*/
	strcpy(message, "Init World");
	writemessage();
	setupscreen();
	drawplayer();
	
	strcpy(message, "Press START");
	writemessage();
	
	waitpad(J_START);
	
	strcpy(message, "Godspeed");
	writemessage();
	
	/*Begin game loop*/
	while(!0)
	{
		updateplayer();
		drawplayer();
		delay(120);
	}
}
