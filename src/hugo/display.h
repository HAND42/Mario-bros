//
// Created by hugod on 01/07/2022.
//
#ifndef __DISPLAY__C__
#define __DISPLAY__C__

#include <SDL_mixer.h>

typedef struct RenduElement{
    SDL_Texture *texture;
    SDL_Rect rectangle;
    SDL_Surface *image;
    int nb1;
    int nb2;
} RenduElement, *Rendu;

// void PlayMusic(Mix_Music *musique);

// void LoadMusic(void);

void displayRender(RenduElement *r, SDL_Renderer *renderer, SDL_Window *window);

void createStartScreen(RenduElement* rendu, SDL_Renderer *renderer, SDL_Window *window);

void displayStartScreen(RenduElement* rendu, SDL_Renderer *renderer, SDL_Window *window, int btn);

void changeImage(RenduElement *r, char* img,SDL_Renderer *renderer, SDL_Window *window);

void createRender (RenduElement *r, SDL_Renderer *renderer, SDL_Window *window,int nb1,int nb2);

void ExitWithError(const char *message);

void SDL_LimitFPS(unsigned int limit);

#endif
