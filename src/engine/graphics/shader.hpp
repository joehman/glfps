#pragma once
#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader() {}
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);


    void use();

    void setInt   (int value,   const char* name);
    void setBool  (bool value,  const char* name);
    void setFloat (float value, const char* name);
    void setMat4  (glm::mat4 value, const char* name);

    
    unsigned int getProgramID() {return m_ProgramID;}
private:
    unsigned int m_ProgramID;

    const char* m_FragShaderPath;
    const char* m_VertShaderPath;

};

#endif
