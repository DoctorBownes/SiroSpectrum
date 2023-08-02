#ifndef RENDERER_H_
#define RENDERER_H_

typedef unsigned int GLuint;


typedef struct Renderer Renderer;
struct Renderer {
	GLuint shaderProgram;
	GLuint GSvertexbuffer;
	GLuint GStexturebuffer;
	GLuint EBO;
};

Renderer renderer;

void SetupRenderer(void);

void RenderGameScreen(void);

#endif
