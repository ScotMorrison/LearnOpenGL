#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderHelpers.h"

unsigned int compileShader(const char* source, int shaderType)
{
    unsigned int vertexShader;
    vertexShader = glCreateShader(shaderType);
    glShaderSource(vertexShader, 1, &source, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return vertexShader;
}

unsigned int CreateShaderProgram(unsigned int shaders[])
{
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    for (int i = 0; i < sizeof(shaders); i++) {
        glAttachShader(shaderProgram, shaders[i]);
    }

    glLinkProgram(shaderProgram);

    for (int i = 0; i < sizeof(shaders); i++) {
        glDeleteShader(shaders[i]);
    }

    int success;
    char infoLog[512];

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shaderProgram;
}