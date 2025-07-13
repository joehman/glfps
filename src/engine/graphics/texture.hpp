#pragma once

#include  <stb_image.h>
#include <glad/glad.h>
#include <inttypes.h>



class Image {
public:
    Image() : m_Data(nullptr) {}
    Image(const char* path);
    ~Image();

    Image(Image&& other); 
    Image& operator=(Image&& other); 

    unsigned char* getData();

    int getWidth() {return m_Width;}
    int getHeight(){return m_Height;}
    int getNrChannels(){return m_NrChannels;}


    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

private:
    unsigned char* m_Data;

    int m_Width, m_Height, m_NrChannels;

};

enum TextureWrapMode {
    MIRRORED_REPEAT = GL_MIRRORED_REPEAT, // repeats and mirrors
    CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER, // clamps to the border of the texture
    CLAMP_TO_EDGE   = GL_CLAMP_TO_EDGE,   // clamps to the edge of the texCoords
    REPEAT          = GL_REPEAT           // repeats
};
enum TextureFilteringMode {
    POINT = GL_NEAREST, // no filtering
    LINEAR = GL_LINEAR  // makes everything smooth
};

// I don't really know what any of these do.
// The linear ones are probably smoother.
enum TextureMipMapFilteringMode {
    NEAREST_MIPMAP_NEAREST  = GL_NEAREST_MIPMAP_NEAREST,
    LINEAR_MIPMAP_NEAREST   = GL_LINEAR_MIPMAP_NEAREST ,

    NEAREST_MIPMAP_LINEAR   = GL_NEAREST_MIPMAP_LINEAR ,
    LINEAR_MIPMAP_LINEAR    = GL_LINEAR_MIPMAP_LINEAR  ,
};

struct TexParameters {
    TextureWrapMode wrapMode;

    TextureFilteringMode filterMode;
    TextureMipMapFilteringMode mipMapFilteringMode;
};

class Texture 
{
public:
    Texture() : m_Texture((unsigned int)NULL)  {};
    Texture(const char* texPath, TexParameters texParams = { 
            .wrapMode = CLAMP_TO_BORDER, 
            .filterMode = POINT,
            .mipMapFilteringMode = NEAREST_MIPMAP_NEAREST
        }); 

    void bindTexture();

private:
    unsigned int m_Texture;
};
