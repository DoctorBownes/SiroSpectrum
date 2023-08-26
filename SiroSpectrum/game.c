#include "game.h"
#include <SiroSpectrum/renderer.h>

Game* newGame(void(*gamecontructor)(), void(*gameloop)()) {
	Game* game = (Game*)malloc(sizeof(Game));

	game->construct = gamecontructor;
	game->loop = gameloop;

	return game;
}

void SetSprite(Sprite sprite, unsigned char colour) {

	for (int i = 0; i < sprite.width * sprite.height; i++) {
		SetPixel(i % sprite.width + sprite.x,
				 i / sprite.width + sprite.y,
					(sprite.canvas[i] & 1) * colour);
	}
}

void SetPixel(unsigned char x, unsigned char y, unsigned char colour) {
	pixelbuffer[x + y * WIN_WIDTH] = colour;
}
