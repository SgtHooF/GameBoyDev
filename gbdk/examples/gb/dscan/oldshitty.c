//----------Includes----------
#include <gb/gb.h>
#include <gb/console.h>
#include <stdio.h>

//--------Declarations--------
UINT8 u_oldX;
UINT8 u_oldY;
UINT8 u_newX;
UINT8 u_newY;
char player;
char floor;
int oldX;
int newX;
int oldY;
int newY;
int key;

//-------structs-------
struct things
{
	char icon;
	int old_X;
	int old_Y;
	int new_X;
	int new_Y;
};

struct things thing1;


//i'm lazy its getting intialised here
// void setupCharacters(character C)
// {
	// C.icon='!';
	// C.old_X=5;
	// C.old_Y=6;
	// C.new_X=5;
	// C.new_Y=6;
// }


//Writes a given char to screen at current cursor location
ps(char ch)
{
	printf("%c",ch);
}

//Draws blank grid of "floor" (full stops '.')
void setupscreen()
{
	int x,y;

	for(y=0;y<17;y++)
	{
		for(x=0;x<19;x++)
		{
			ps(floor);
		}
		
		printf("\n");
	}
}

//Draws a char at the given location
/*Originally this function included drawing a floor tile in the old location and then draw the given char at the new location. 
It's still mega vague and only works with the current "player" setup, but meh*/

/*Oh yeh and it has to convert into UINT8's to do so */
void draw(int ox, int oy, int nx, int ny, char ch)
{
	u_oldX=ox;
	u_oldY=oy;
	
	u_newX=nx;
	u_newY=ny;
	
	gotoxy(u_oldX,u_oldY);
	ps(floor);
	
	gotoxy(u_newX,u_newY);
	ps(ch);
}



//Updates the player location based on input.
void update()
{
	key=joypad();
	thing1.old_X=thing1.new_X;
	thing1.old_Y=thing1.new_Y;
	
	if(key & J_UP)
	{
		thing1.new_Y=(thing1.old_Y-1);
	}
	if(key & J_DOWN)
	{
		thing1.new_Y=(thing1.old_Y+1);
	}
	if(key & J_LEFT)
	{
		thing1.new_X=(thing1.old_X-1);
	}
	if(key & J_RIGHT)
	{
		thing1.new_X=(thing1.old_X+1);
	}
	
	//check for map bounds
	if(thing1.new_X < 0)
	{
		thing1.new_X=0;
	}
	if(thing1.new_X > 16)
	{
		thing1.new_X=16;
	}
	if(thing1.new_Y < 0)
	{
		thing1.new_Y=0;
	}
	if(thing1.new_Y > 18)
	{
		thing1.new_Y=18;
	}
}
void newDraw( struct things thing )
//------------Main method!!! yay!!---------
void main()
{
	oldX=5;
	newX=6;
	oldY=5;
	newY=6;
	
	player = '!';
	floor = '.';
	
	//thing;
	
	
	thing1.icon='!';
	thing1.old_X=5;
	thing1.old_Y=6;
	thing1.new_X=5;
	thing1.new_Y=6;
	
	//setupCharacters(Player);
	
	
	setupscreen();
	
	
	
	
	waitpad(J_START);
	
	while(!0)
	{
		update();
		draw(oldX, oldY, newX, newY, player);
		//delay for emulator (bugger me its fast)
		delay(200);
	}
}

void newdraw(struct things D)
{
	u_oldX=D.old_X;
	u_oldY=D.old_Y;
	
	u_newX=D.new_X;
	u_newY=D.newY;
	
	gotoxy(u_oldX,u_oldY);
	ps(floor);
	
	gotoxy(u_newX,u_newY);
	ps(D.icon);
}