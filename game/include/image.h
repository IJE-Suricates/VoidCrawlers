/*
 * Classe que representa uma imagem.
 *
 * Autor: Jefferson Xavier
 * Data: 16/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "exception.h"
#include "resource.h"

using std::string;

class Image : public Resource
{
public:
    ~Image();

    int w() const;
    int h() const;

    static Image * from_file(const string& path) throw (Exception);

    SDL_Texture * texture() const;

    Uint8 alpha;

private:
    Image(SDL_Texture *texture, const string& id, int w, int h);

    SDL_Texture *m_texture;
    int m_w, m_h;
};

#endif
