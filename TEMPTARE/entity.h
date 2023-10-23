#ifndef ENTITY_H_
#define ENTITY_H_

typedef struct HitBox {
	unsigned char x;
	unsigned char y;
	unsigned char width;
	unsigned char height;
} HitBox;

typedef struct Entity {
	unsigned char x;
	unsigned char y;
	unsigned char colstat;
	struct Sprite* sprite;
} Entity;

#endif