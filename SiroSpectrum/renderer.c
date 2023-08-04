#include "renderer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WHT 255,255,255
#define RED 255,0,0

const char* vertex_shader =
"#version 330 core\n"
"layout(location = 0) in vec4 vertexPosition;\n"
"out vec2 UV;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(vertexPosition.x ,vertexPosition.y,0.0f, 1.0f);\n"
"	UV = vec2(vertexPosition.z ,vertexPosition.w);\n"
"};\0";

const char* fragment_shader =
"#version 330 core\n"
"in vec2 UV;\n"
"out vec4 FragColor;\n"
"uniform sampler2D BGTextureSampler;\n"
"void main()\n"
"{\n"
"	FragColor = texture2D(BGTextureSampler, UV);\n"
"};\0";

void SetupRenderer(void) {

    renderer.shaderProgram = 0;
    // Compile Vertex Shader
    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(VertexShader, 1, &vertex_shader, NULL);
    glCompileShader(VertexShader);

    // Check Vertex Shader
    //glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &Result);
    //glGetShaderiv(VertexShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
    //    glGetShaderInfoLog(VertexShader, InfoLogLength, nullptr, &VertexShaderErrorMessage[0]);
    //    printf("%s", &VertexShaderErrorMessage[0]);
    //}

    // Compile Fragment Shader
    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(FragmentShader, 1, &fragment_shader, NULL);
    glCompileShader(FragmentShader);

    // Check Fragment Shader
    //glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &Result);
    //glGetShaderiv(FragmentShader, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
    //    glGetShaderInfoLog(FragmentShader, InfoLogLength, nullptr, &FragmentShaderErrorMessage[0]);
    //    printf("%s", &FragmentShaderErrorMessage[0]);
    //}

    // Link the program
    renderer.shaderProgram = glCreateProgram();
    glAttachShader(renderer.shaderProgram, VertexShader);
    glAttachShader(renderer.shaderProgram, FragmentShader);
    glLinkProgram(renderer.shaderProgram);

    // Check the program
    //glGetProgramiv(shaderProgram, GL_LINK_STATUS, &Result);
    //glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
    //if (InfoLogLength > 0) {
    //    std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
    //    glGetProgramInfoLog(shaderProgram, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
    //    printf("%s", &ProgramErrorMessage[0]);
    //}

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);

    glUseProgram(renderer.shaderProgram);

    GLuint Init;
    glGenVertexArrays(1, &Init);
    glBindVertexArray(Init);
    
    static const GLfloat GS_vertex_buffer_data[] = {
         0.5f,  0.5f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f,  1.0f, 0.0f,
    };
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    glGenBuffers(1, &renderer.GSvertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, renderer.GSvertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GS_vertex_buffer_data), GS_vertex_buffer_data, GL_STATIC_DRAW);


    glGenBuffers(1, &renderer.EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer.EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    unsigned char texture[] = {
        RED,WHT,WHT,WHT,WHT,WHT,WHT,RED,
        WHT,WHT,WHT,WHT,WHT,WHT,WHT,WHT,
        WHT,WHT,RED,WHT,WHT,RED,WHT,WHT,
        WHT,WHT,WHT,WHT,WHT,WHT,WHT,WHT,
        WHT,RED,WHT,WHT,WHT,WHT,RED,WHT,
        WHT,WHT,RED,RED,RED,RED,WHT,WHT,
        WHT,WHT,WHT,WHT,WHT,WHT,WHT,WHT,
        RED,WHT,WHT,WHT,WHT,WHT,WHT,RED,
    };


    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &renderer.GStexturebuffer);
    glBindTexture(GL_TEXTURE_2D, renderer.GStexturebuffer);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 8, 8, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
    glUniform1i(glGetUniformLocation(renderer.shaderProgram, "BGTextureSampler"), 0);

}

void RenderGameScreen(void){

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, renderer.GStexturebuffer);
    glUniform1i(glGetUniformLocation(renderer.shaderProgram, "BGTextureSampler"), 0);

    glBindBuffer(GL_ARRAY_BUFFER, renderer.GSvertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        4,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                   // stride
        (void*)0            // array buffer offset
    );
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderer.EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
