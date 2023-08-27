#ifndef GAME_H_
#define GAME_H_

#include <SiroSpectrum/sprite.h>
#include <SiroSpectrum/input.h>

typedef struct Game Game;
struct Game {
	void (*loop)();
	void (*construct)();
};

Game* newGame(void (*gamecontructor)(),void (*gameloop)());

void SetSprite(Sprite sprite, unsigned char colour);

void SetPixel(unsigned char x, unsigned char y, unsigned char colour);

#endif
