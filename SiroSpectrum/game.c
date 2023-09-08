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

	switch (colour >> 4) {
	case 1:
		for (unsigned char y = 0; y < sprite.height; y++) {
			for (unsigned char x = sprite.width; x > 0; x--) {
				SetPixel(x + xpos -1, y + ypos, sprite.canvas[row] * colour);
				row++;
			}
		}
		break;
	case 2:
		for (unsigned char y = sprite.height; y > 0; y--) {
			for (unsigned char x = 0; x < sprite.width; x++) {
				SetPixel(x + xpos, y + ypos -1, sprite.canvas[row] * colour);
				row++;
			}
		}
		break;
	case 3:
		for (unsigned char y = sprite.height; y > 0; y--) {
			for (unsigned char x = sprite.width; x > 0; x--) {
				SetPixel(x + xpos -1, y + ypos -1, sprite.canvas[row] * colour);
				row++;
			}
		}
		break;
	default:
		for (unsigned char y = 0; y < sprite.height; y++) {
			for (unsigned char x = 0; x < sprite.width; x++) {
				SetPixel(x + xpos, y + ypos, sprite.canvas[row] * colour);
				row++;
			}
		}
		break;
	}

	//unsigned char dirx = colour >> 4 & 1;
	//unsigned char diry = colour >> 5 & 1;
	//for (unsigned char y = 0 + sprite.height * diry; y * (1 - 2 * diry) < 0 + sprite.height * (~diry & 1); y += (1 - 2 * diry)) {
	//	for (unsigned char x = 0 + sprite.width * dirx; x * (1 - 2 * dirx) < 0 + sprite.width * (~dirx & 1); x += (1 - 2 * dirx)) {
	//		SetPixel(x + xpos - dirx, y + ypos - diry, sprite.canvas[row] * colour);
	//		row++;
	//	}
	//}
}

void RemoveSprite(Sprite sprite, unsigned char xpos, unsigned char ypos) {
	for (unsigned char y = 0; y < sprite.height; y++) {
		for (unsigned char x = 0; x < sprite.width; x++) {
			pixelbuffer[y + ypos][x + xpos] = 0;
		}
	}
}

void SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	if (colour) {
		pixelbuffer[ypos][xpos] = colour & 15;
	}
}

void SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour) {
	backgroundcolors[ypos][xpos] = colour & 15;
}
