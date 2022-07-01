//
// Created by hugod on 01/07/2022.
//
#ifndef __DISPLAY__C__
#define __DISPLAY__C__

void createRender (const char *img, 
    SDL_Renderer *renderer, 
    SDL_Window *window,
    int nb1,
    int nb2);

void SDL_ExitWithError(const char *message);

void SDL_LimitFPS(unsigned int limit);

#endif
