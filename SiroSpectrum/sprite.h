#ifndef SPRITE_H_
#define SPRITE_H_

typedef struct Sprite Sprite;
struct Sprite {
	unsigned char* canvas;
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
};

#endif
