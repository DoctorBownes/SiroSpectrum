#include "game.h"

Game* newGame(void(*gamecontructor)(), void(*gameloop)()) {
	Game* game = (Game*)malloc(sizeof(Game));

	game->construct = gamecontructor;
	game->loop = gameloop;

	return game;
}
