#include <SiroSpectrum/core.h>
#include <SiroSpectrum/game.h>
#include <stdio.h>

void loopdiloop() {
	printf("LOOOOOP!\n");
}
void constring() {
	printf("Constructing!\n");
}

int main(void) {
	Game* fungame = newGame(constring, loopdiloop);

	RunGame(fungame);

	return 0;
}