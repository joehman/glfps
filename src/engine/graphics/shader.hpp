#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>
#include <iostream>

class Shader
{
public:
    Shader() {}
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);

    void use();

    
    
    unsigned int getProgramID() {return m_ProgramID;}
private:
    unsigned int m_ProgramID;

};

#endif
