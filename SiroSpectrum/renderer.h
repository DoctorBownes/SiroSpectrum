#ifndef RENDERER_H_
#define RENDERER_H_

typedef unsigned int GLuint;


typedef struct Renderer Renderer;
struct Renderer {
	GLuint shaderProgram;
	GLuint vertexbuffer;
	GLuint BGtexturesampler;
	GLuint FGtexturesampler;
	GLuint PaletteSampler;
	GLuint EBO;
};

Renderer renderer;

void SetupRenderer(void);

void RenderGameScreen(void);

#endif
