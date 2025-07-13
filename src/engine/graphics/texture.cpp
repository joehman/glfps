#include "texture.hpp"
#include <fstream>
#include <GL/gl.h>
#include <print>


#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(const char* texPath, TexParameters texParams)
{


    Image image(texPath);
    if (image.getData() == nullptr)
    {
        std::println("Failed to find image for texture!");
    }

    int nrChannels = image.getNrChannels();
    int width = image.getWidth();
    int height = image.getHeight();

    glGenTextures(1, &m_Texture);
    glBindTexture(GL_TEXTURE_2D, m_Texture);
       
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texParams.wrapMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texParams.wrapMode);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texParams.mipMapFilteringMode);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texParams.filterMode);

    std::println("nrChannels: {}", image.getNrChannels());

    if (nrChannels == 3)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getData());
    } else if (nrChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());
    } else {
        std::println("ERROR: Invalid texture format for texture {}", texPath);
    }
    glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::bindTexture()
{
    glBindTexture(GL_TEXTURE_2D, m_Texture);
}

// the two functions below exist to prevent an Image from unintentionally freeing its data 
// when moving it to another Image object.
// ex. 
// 
// without this:
// Image a;
// a = Image("image.png");
// > segfault when opengl tries to read, because the m_Data has already been freed by the destructor  
//
// with:
// Image a;
// a = Image("image.png");
// > no segfault because the m_Data isn't freed by the destructor
Image::Image(Image&& other)
{
    m_Data = other.m_Data;
    m_NrChannels = other.m_NrChannels;
    m_Width = other.m_Width;
    m_Height = other.m_Height;

    other.m_Data = nullptr;
}
Image& Image::operator=(Image&& other) {
    if (this != &other) {
        
        stbi_image_free(m_Data);
        m_Data = other.m_Data;
        m_Width = other.m_Width;
        m_Height = other.m_Height;
        m_NrChannels = other.m_NrChannels;

        other.m_Data = nullptr;
    }
    return *this;
} 
Image::Image(const char* path)
{
    std::fstream file(path);
    if (!file.good())
    {
        std::println("Failed to find Image at {}", path);
        m_Data = nullptr;
        return;
    }

    stbi_set_flip_vertically_on_load(true);
    m_Data = stbi_load(path, &m_Width,&m_Height,&m_NrChannels, 0); 
}
Image::~Image()
{
    if (m_Data != nullptr)
    {
        stbi_image_free(m_Data);
    }
}
unsigned char* Image::getData()
{
    return m_Data;
}
