#include <SiroSpectrum/core.h>
#include <SiroSpectrum/game.h>
#include <stdio.h>

void updatePlayer() {

}

void loopdiloop() {
	printf("loop\n");
}
void constring() {
	printf("constructing\n");
	unsigned char stefanvas[8 * 16] = {
		0,0,0,1,1,1,0,0,
		0,0,1,1,1,1,1,0,
		0,1,1,1,1,1,0,0,
		0,1,1,1,0,1,0,0,
		0,1,1,1,1,1,1,0,
		0,0,1,1,1,1,0,0,
		0,0,0,1,1,0,0,0,
		0,0,1,0,0,1,0,0,
		0,1,1,1,1,1,1,0,
		0,1,0,1,1,1,1,0,
		0,0,0,1,1,1,0,0,
		0,1,0,0,0,0,1,0,
		0,0,1,1,1,1,0,0,
		0,0,1,1,0,1,0,0,
		0,0,1,0,1,1,0,0,
		0,0,1,1,0,1,1,0,
	};

	Sprite Stefan = { stefanvas, 0, 0, 8,16};
	Stefan.x = 7;
	Stefan.y = 7;
	SetSprite(Stefan, 4);

	SetPixel(65, 128, 2);
}

int main(void) {
	Game* fungame = newGame(constring, loopdiloop);

	RunGame(fungame);

	return 0;
}