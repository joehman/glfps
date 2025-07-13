#include "shader.hpp"
#include <engine/util/util.hpp>

void checkShaderComp(unsigned int shader)
{
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "Shader Compilation Error!: \n" << infoLog << '\n';
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
        std::cout << "Shader Linking Error!: \n" << infoLog << '\n';
    }
}

Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    std::string vertexSource = Util::loadTextFromFile(vertexShaderPath.c_str());
    //looks strange but segfaults without it
    const char* vSource = vertexSource.c_str();
    glShaderSource(vertexShader, 1, &vSource, NULL);
    glCompileShader(vertexShader);

    checkShaderComp(vertexShader);

    std::string fragmentShaderSource = Util::loadTextFromFile(fragmentShaderPath.c_str());
    const char* fSource = fragmentShaderSource.c_str();
    glShaderSource(fragmentShader, 1, &fSource, NULL);
    glCompileShader(fragmentShader);


    checkShaderComp(fragmentShader);

    this->m_ProgramID = glCreateProgram();
    glAttachShader(m_ProgramID, vertexShader);
    glAttachShader(m_ProgramID, fragmentShader);
    glLinkProgram(m_ProgramID);
    
    checkProgramLink(m_ProgramID);
    

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(this->m_ProgramID);
}
