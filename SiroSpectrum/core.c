#include <SiroSpectrum/core.h>
#include <SiroSpectrum/game.h>
#include <SiroSpectrum/renderer.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport((width - 1024) / 2, (height - 768) / 2, 1024, 768);
};


void CreateWindow() {
    _window = NULL;
    _starttime = 0.0;
    _reset = 1;
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(1024, 768, "SiroSpectrum", NULL, NULL);

    if (_window == NULL) {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return;
    }
    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    glfwMakeContextCurrent(_window);
    //glfwSwapInterval(0);

    if (!gladLoadGL()) {
        fprintf(stderr, "Failed to initialize GLAD.\n");
        glfwTerminate();
    }

    SetupRenderer();
}

void ResetWindow(){
    _reset = 1;
};

int CloseWindow(){
    return (glfwWindowShouldClose(_window));
};

void RunGame(Game* game) {
    if (glfwGetTime() - _starttime > 0.0162f) {//60 FPS CAP
        glClear(GL_COLOR_BUFFER_BIT);

        _presscalled = 0;
        _relescalled = 0;
    
        if (_reset) {

            for (int y = 0; y < WIN_HEIGHT; y++) {
                for (int x = 0; x < WIN_WIDTH; x++) {
                    pixelbuffer[y][x] = 0;
                }
            }
            for (int y = 0; y < WIN_HEIGHT / TILESIZE; y++) {
                for (int x = 0; x < WIN_WIDTH / TILESIZE; x++) {
                    backgroundcolors[y][x] = 0;
                }
            }
    
            game->constructor();
    
            _reset = 0;
        }
    
        game->tick();
    
        DrawGameScreen();
        
        RenderGameScreen();
    
        glfwSwapBuffers(_window);
        glfwPollEvents();
    
        _starttime = glfwGetTime();
    }
};