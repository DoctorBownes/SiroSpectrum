#ifndef CHECKPOINT_H_
#define CHECKPOINT_H_

typedef struct CheckPoint {
	unsigned char x;
	unsigned char y;
	unsigned char status;
	void (*function)();
} CheckPoint;

#endif