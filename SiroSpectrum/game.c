#include "game.h"
#include <SiroSpectrum/renderer.h>

Game* newGame(void(*gamecontructor)(), void(*gameloop)()) {
	Game* game = (Game*)malloc(sizeof(Game));

	game->construct = gamecontructor;
	game->loop = gameloop;

	return game;
}

void SetSprite(Sprite sprite, unsigned char xpos, unsigned char ypos, unsigned char colour) {
	unsigned char row = 0;
	for (unsigned char y = 0; y < sprite.height; y++) {
		for (unsigned char x = 0; x < sprite.width; x++) {
			SetPixel(x + xpos, y + ypos, sprite.canvas[row] * colour);
			row++;
		}
	}
}

void SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	pixelbuffer[ypos][xpos] = colour;
}

void SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	backgroundcolors[ypos][xpos] = colour;
}
