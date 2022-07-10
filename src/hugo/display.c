//
// Created by hugod on 30/06/2022.
//
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#include <SDL_mixer.h>


#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066

#define FPS_LIMIT 33

// void PlayMusic(Mix_Music *musique){
//     Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
// }

// void LoadMusic(void){
//     if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
//     {
//        printf("%s", Mix_GetError());
//     }
//     Mix_VolumeMusic(MIX_MAX_VOLUME / 2); //Mettre le volume à la moitié
// }


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

void createRender (RenduElement *r, SDL_Renderer *renderer, SDL_Window *window,int nb1,int nb2)
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

    // SDL_FreeSurface(r->image);
    // SDL_DestroyTexture(r->texture);
    return;
}

void displayRender(RenduElement *r, SDL_Renderer *renderer, SDL_Window *window){
    if (SDL_QueryTexture(r->texture, NULL, NULL, &(r->rectangle.w), &(r->rectangle.h)) !=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de charger la texture");
        return;

    }

    if (SDL_RenderCopy(renderer, r->texture, NULL, &(r->rectangle))!=0){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible d'afficher la texture");
        return;
    }
    return;
}


void changeImage(RenduElement *r, char* img,SDL_Renderer *renderer, SDL_Window *window){
    r->image = SDL_LoadBMP(img);

    r->texture = SDL_CreateTextureFromSurface(renderer, r->image);

    if (r->texture ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de creer la texture");
        return;
    }
    return;
}

void createStartScreen(RenduElement* rendu, SDL_Renderer *renderer, SDL_Window *window){
    int nbelem = sizeof(rendu)/sizeof(rendu[0]);
    //printf("%d\n", nbelem);
     for (int i = 0 ; i < 7 ; i++)
    {

        createRender(&(rendu[i]), renderer, window, rendu[i].nb1, rendu[i].nb2);

    }
    return;

}

void displayStartScreen(RenduElement* rendu, SDL_Renderer *renderer, SDL_Window *window, int btn){
    int nbelem = sizeof(rendu)/sizeof(rendu[0]);
    //printf("%d\n", nbelem);
    if (btn==3){
        displayRender(&(rendu[0]), renderer, window);
        return;
    }
    for (int i = 0 ; i < 5 ; i++)
    {

        displayRender(&(rendu[i]), renderer, window);

    }
    if (btn==1){
        displayRender(&(rendu[5]), renderer, window);
    }
    else if(btn==2){
        displayRender(&(rendu[6]), renderer, window);
    }
    return;

}