#include <SiroSpectrum/core.h>
#include <SiroSpectrum/game.h>
#include <SiroSpectrum/renderer.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //glViewport(0,0,width, height);
    glViewport((width - 1024) / 2, (height - 960) / 2, 1024, 960);
};


void SetupWindow() {
    _window = NULL;
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    _window = glfwCreateWindow(1024, 960, "SiroSpectrum", NULL, NULL);

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
};

void RunGame(Game* game) {

    SetupWindow();

    SetupRenderer();

    double starttime = 0.0;

    if (!game->loop || !game->construct) {
        printf("Error: No loop or contruct function found!\nMake sure you assign .loop and .construct to a function.\n");
        return;
    }

    game->construct();

    do {
        if (glfwGetTime() - starttime > 0.0162f) {//60 FPS CAP
            glClearColor(113 / 255.0f, 62 / 255.0f, 255.0f / 255.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            game->loop();
            
            RenderGameScreen();

            glfwSwapBuffers(_window);
            glfwPollEvents();

            starttime = glfwGetTime();
        }
    } while (!glfwWindowShouldClose(_window));
};