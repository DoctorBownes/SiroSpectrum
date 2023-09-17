#ifndef RENDERER_H_
#define RENDERER_H_

#define WIN_WIDTH 256
#define WIN_HEIGHT 192
#define TILESIZE 8

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

unsigned char backgroundcolors[WIN_HEIGHT / TILESIZE][WIN_WIDTH / TILESIZE];
unsigned char pixelbuffer[WIN_HEIGHT][WIN_WIDTH];

Renderer renderer;

struct GLFWwindow* _window;

void SetupRenderer(void);

void DrawGameScreen(void);

void RenderGameScreen(void);

double _starttime;

unsigned char _reset;

#endif
