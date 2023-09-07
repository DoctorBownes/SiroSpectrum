#include <SiroSpectrum/core.h>
#include <SiroSpectrum/game.h>
#include <stdio.h>

unsigned char stefanvas[8 * 16] = {
	0,0,0,1,1,1,0,0,
	0,0,1,1,1,1,1,0,
	0,1,1,1,1,1,0,0,
	0,1,1,1,0,1,0,0,
	0,1,1,1,1,1,1,0,
	0,0,1,1,1,1,0,0,
	0,0,0,1,1,0,0,0,
	0,0,1,0,0,1,0,0,
	0,1,1,1,1,1,1,0,
	0,1,0,1,1,1,1,0,
	0,0,0,1,1,1,0,0,
	0,1,0,0,0,0,1,0,
	0,0,1,1,1,1,0,0,
	0,0,1,1,0,1,0,0,
	0,0,1,0,1,1,0,0,
	0,0,1,1,0,1,1,0,
};

unsigned char wall[8 * 8] = {
	0,1,0,0,0,0,0,0,
	0,1,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,
	0,0,0,0,0,1,0,0,
	0,0,0,0,0,1,0,0,
	0,0,0,0,0,1,0,0,
	1,1,1,1,1,1,1,1,
	0,1,0,0,0,0,0,0,
};
unsigned char cat[] ={
	1,0,0,0,1,0,0,1,
	1,0,0,0,1,1,1,1,
	1,1,0,0,1,0,1,0,
	0,1,1,1,1,1,1,1,
	0,0,1,1,1,1,1,0,
	0,0,1,0,1,0,1,0,
};
Sprite Wall = {wall, 8, 8};
Sprite Stefan = {stefanvas, 8, 16};
Sprite downey = { cat, 8, 6 };

unsigned char plr_x = 0;
unsigned char plr_y = 0;
unsigned char dir = 0b001000;

void loopdiloop() {
	SetSprite(Stefan, plr_x, plr_y, 0);
	if (GetKey(Right)) {
		plr_x +=2;
		dir = 0b00001000;
	}
	 if (GetKey(Left)) {
		plr_x -=2;
		dir = 0b00011000;
	}
	 if (GetKey(Up)) {
		plr_y -=2;
	}
	 if (GetKey(Down)) {
		plr_y += 2;
	}
	SetSprite(Stefan, plr_x, plr_y, dir);

	SetSprite(Stefan, 32, 0, dir);
	SetSprite(Stefan, 40, 0, 0b00011000);
	SetSprite(Stefan, 48, 0, 0b00101000);
	SetSprite(Stefan, 56, 0, 56);
	SetSprite(Stefan, 64, 0, 0b00010111);
	SetSprite(Stefan, 72, 0, 0b00110111);
}
void constring() {
	printf("constructing\n");
	plr_x = 8;
	plr_y = 8;

	for (int i = 0; i < 256; i += 8) {
		SetSprite(Wall, i, 0, 1);
		SetBGColour(i / 8, 0, 2);
	}
	for (int i = 8; i < 192; i += 8) {
		SetSprite(Wall, 0, i, 1);
		SetBGColour(0, i / 8, 2);
	}
	for (int i = 8; i < 256; i += 8) {
		SetSprite(Wall, i, 184, 1);
		SetBGColour(i / 8, 23, 2);
	}
	for (int i = 8; i < 192; i += 8) {
		SetSprite(Wall, 248, i, 1);
		SetBGColour(31, i / 8, 2);
	}
	SetSprite(downey, 100, 100, 3);
	SetPixel(101, 105, 2);
}

int main(void) {
	Game* fungame = newGame(constring, loopdiloop);

	RunGame(fungame);

	return 0;
}