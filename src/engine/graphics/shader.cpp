#include "shader.hpp"
#include <engine/util/util.hpp>
#include <print>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

void checkShaderComp(unsigned int shader, const char* path)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::println("Shader compilation error from: {} \n {}", path, infoLog);
    }
}
void checkProgramLink(unsigned int program)
{
    int success;
    char infoLog[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::println("Shader Program Linking Error!: \n {} ", infoLog );
    }
}
void compileShader(uint shader, std::string source)
{
    const char* shaderSource = source.c_str(); 
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);
}

//assumes uint program is already a created shader program
void linkProgram(uint program, uint vertexShader, uint fragmentShader)
{
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexSource = Util::loadTextFromFile(vertexShaderPath.c_str());
    compileShader(vertexShader, vertexSource);
    checkShaderComp(vertexShader, vertexShaderPath.c_str());

    std::string fragmentShaderSource = Util::loadTextFromFile(fragmentShaderPath.c_str());
    compileShader(fragmentShader, fragmentShaderSource);
    checkShaderComp(fragmentShader, fragmentShaderPath.c_str());

    this->m_ProgramID = glCreateProgram();
    linkProgram(m_ProgramID, vertexShader, fragmentShader);
    checkProgramLink(m_ProgramID);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(this->m_ProgramID);
}
void Shader::setInt(int value, const char* name)
{
    int location = glGetUniformLocation(m_ProgramID, name);
    glUniform1i(location, value);
}
// note : you can also set ints with this function
void Shader::setBool(bool value, const char* name)
{
    int location = glGetUniformLocation(m_ProgramID, name);
    glUniform1i(location, (int)value); 
}
void Shader::setFloat(float value, const char* name)
{
    int location = glGetUniformLocation(m_ProgramID, name);
    glUniform1f(location, value);
}
void Shader::setMat4(glm::mat4 value, const char* name)
{
    int location = glGetUniformLocation(m_ProgramID, name);
    glUniformMatrix4fv(location,1, GL_FALSE, glm::value_ptr(value));
}
