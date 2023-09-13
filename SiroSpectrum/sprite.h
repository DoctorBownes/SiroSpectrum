#ifndef SPRITE_H_
#define SPRITE_H_

typedef struct Sprite {
	unsigned char* canvas;
	unsigned char width;
	unsigned char height;
}Sprite;

typedef struct Tile {
	unsigned char canvas[8 * 8];
	unsigned char colour;
}Tile;

#endif
