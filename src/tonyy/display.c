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

void ExitWithError(const char *message){
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

void createRender (Rendu * r, SDL_Renderer *renderer, SDL_Window *window,int nb1,int nb2)
{
    //SDL_Texture *texture = NULL;
    //SDL_Surface *image = NULL;
    //SDL_Rect rectangle;


    //r->image = SDL_LoadBMP(img);

    if (r->image ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de charger l'image");
        return;
    }

    r->texture = SDL_CreateTextureFromSurface(renderer, r->image);

    if (r->texture ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de creer la texture");
        return;
    }


    if (SDL_QueryTexture(r->texture, NULL, NULL, &(r->rectangle.w), &(r->rectangle.h)) !=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de charger la texture");
        return;

    }

    r->rectangle.x = (WINDOW_WIDTH - r->rectangle.w)/2;
    r->rectangle.y = (WINDOW_HEIGHT - nb1*r->rectangle.h)/nb2;

    if (SDL_RenderCopy(renderer, r->texture, NULL, &(r->rectangle))!=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible d'afficher la texture");
        return;
    }


    //SDL_FreeSurface(image);
    //SDL_DestroyTexture(texture);
    return;
}