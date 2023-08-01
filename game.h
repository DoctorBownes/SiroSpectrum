#ifndef GAME_H_
#define GAME_H_

typedef struct Game Game;
struct Game {
	void (*loop)();
	void (*construct)();
};

Game* newGame(void (*gamecontructor)(),void (*gameloop)());

#endif
