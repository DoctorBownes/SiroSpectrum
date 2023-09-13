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

void SetSprite(Sprite sprite, unsigned char xpos, unsigned char ypos, unsigned char colour);

void SetTile(Tile tile, unsigned char x, unsigned char y);

void RemoveSprite(Sprite sprite, unsigned char xpos, unsigned char ypos);

void SetPixel(unsigned char xpos, unsigned char ypos, unsigned char colour);

void SetBGColour(unsigned char xpos, unsigned char ypos, unsigned char colour);

#endif
