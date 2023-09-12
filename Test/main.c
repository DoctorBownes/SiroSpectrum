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
	0,1,1,1,1,1,0,0,
	0,1,0,1,1,1,0,0,
	0,0,0,1,1,1,0,0,
	0,1,0,0,0,0,1,0,
	0,0,1,1,1,1,0,0,
	0,0,1,1,0,1,0,0,
	0,0,1,0,1,1,0,0,
	0,0,1,1,0,1,1,0,
};

unsigned char stefanvas1[8 * 16] = { 
0,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,
0,1,1,1,0,1,0,0,
0,1,1,1,1,1,1,0,
0,0,1,1,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,1,0,0,1,0,0,
0,1,1,1,1,1,1,0,
1,0,0,1,1,1,1,0,
0,0,1,1,1,1,0,1,
1,0,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,1,1,1,0,1,1,0,
1,1,0,0,0,1,1,1,
0,1,1,0,0,0,1,0,
};

unsigned char stefanvas2[8 * 16] = {
0,0,0,1,1,1,0,0,
0,0,1,1,1,1,1,0,
0,1,1,1,1,1,1,0,
0,1,1,1,0,1,0,0,
0,1,1,1,1,1,1,0,
0,0,1,1,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,1,0,0,1,0,0,
0,1,1,1,1,1,0,0,
0,1,0,1,1,1,0,0,
0,1,0,1,1,1,0,0,
0,0,1,0,0,0,0,0,
0,0,0,1,1,1,0,0,
0,0,1,1,0,1,0,0,
0,0,1,0,1,0,0,0,
0,0,0,1,0,1,0,0, 
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
Sprite Stefan1 = {stefanvas1, 8, 16};
Sprite Stefan2 = {stefanvas2, 8, 16};
Sprite downey = { cat, 8, 6 };
Sprite stef_walk[3];

unsigned char plr_x = 0;
unsigned char plr_y = 0;
unsigned char dir = 0b0001000;
unsigned char frame = 0;
unsigned char timer = 0;

void constring() {
	plr_x = 0;
	plr_y = 168;
	frame = 0;
	stef_walk[1] = Stefan;
	stef_walk[0] = Stefan1;
	stef_walk[2] = Stefan2;
	//for (int i = 0; i < 256; i += 8) {
	//	SetSprite(Wall, i, 0, 1);
	//	SetBGColour(i / 8, 0, 2);
	//}
	//for (int i = 8; i < 192; i += 8) {
	//	SetSprite(Wall, 0, i, 1);
	//	SetBGColour(0, i / 8, 2);
	//}
	//for (int i = 8; i < 256; i += 8) {
	//	SetSprite(Wall, i, 184, 1);
	//	SetBGColour(i / 8, 23, 2);
	//}
	//for (int i = 8; i < 192; i += 8) {
	//	SetSprite(Wall, 248, i, 1);
	//	SetBGColour(31, i / 8, 2);
	//}
	//for (int i = 0; i < 24; i++) {
	//	for (int j = 0; j < 32; j++) {
	//		SetBGColour(j, i, 2);
	//	}
	//}
}

void loopdiloop() {
	RemoveSprite(Stefan, plr_x, plr_y);
	if (GetKey(Right)) {
		//if (plr_x < 240) {
			plr_x += 2;
			dir = 0b00001000;
		//}
	}
	 if (GetKey(Left)) {
		// if (plr_x > 8) {
			 plr_x -= 2;
			 dir = 0b00011000;
		// }
	}
	 if (GetKey(Up)) {
		// if (plr_y > 8) {
			 plr_y -= 2;
		// }
	}
	 if (GetKey(Down)) {
		// if (plr_y < 168) {
			 plr_y += 2;
		// }
	}
	SetSprite(stef_walk[frame], plr_x, plr_y, dir);
	SetSprite(downey, 128, 100, 7);
	if (timer / 8) {
		frame++;
		if (frame >= 3) {
			frame = 0;
		}
		timer = 0;
	}
	timer++;
}

int main(void) {
	Game* fungame = newGame(constring, loopdiloop);

	RunGame(fungame);

	return 0;
}