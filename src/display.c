//
// Created by hugod on 30/06/2022.
//
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066

#define FPS_LIMIT 33

void SDL_ExitWithError(const char *message){
    SDL_Log("ERREUR : %S > %s \n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

void SDL_LimitFPS(unsigned int limit)
{
    unsigned int ticks = SDL_GetTicks();

    if (limit < ticks)
        return;
    else if(limit > ticks + FPS_LIMIT)
        SDL_Delay(FPS_LIMIT);
    else
        SDL_Delay(limit - ticks);
}

void createRender (const char *img, 
    SDL_Renderer *renderer, 
    SDL_Window *window,
    int nb1,
    int nb2)
{
    SDL_Texture *texture = NULL;
    SDL_Surface *image = NULL;



    image = SDL_LoadBMP(img);

    if (image ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger l'image");
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    if (texture ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de creer la texture");
        return;
    }

    SDL_Rect rectangle;

    if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) !=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible de charger la texture");
        return;

    }

    rectangle.x = (WINDOW_WIDTH - rectangle.w)/2;
    rectangle.y = (WINDOW_HEIGHT - nb1*rectangle.h)/nb2;

    if (SDL_RenderCopy(renderer, texture, NULL, &rectangle)!=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_ExitWithError("Impossible d'afficher la texture");
        return;
    }
}