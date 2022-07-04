//
// Created by hugod on 01/07/2022.
//
#ifndef __DISPLAY__C__
#define __DISPLAY__C__

typedef struct RenduElement{
    SDL_Texture *texture;
    SDL_Rect rectangle;
    SDL_Surface *image;
} RenduElement, *Rendu;




void createRender (Rendu r, SDL_Renderer *renderer, SDL_Window *window,int nb1,int nb2);

void ExitWithError(const char *message);

void SDL_LimitFPS(unsigned int limit);

#endif
