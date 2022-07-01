//
// Created by Hugodurand on 30/06/2022.
//
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "display.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066

#define FPS_LIMIT 33

void SDL_ExitWithError(const char *message);
void SDL_LimitFPS(unsigned int limit);
void createRender (const char *img, SDL_Renderer *renderer, 
    SDL_Window *window,
    int nb1,
    int nb2);

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    //Lancement SDL
    if (SDL_Init(SDL_INIT_VIDEO) !=0)
        SDL_ExitWithError("Initialisation SDL");

    //Creation fenetre + rendu 
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer)!=0)
        SDL_ExitWithError("Impossible de créer la fenetre et le rendu");

    /*------------------Background Landscape Start Render----------------------------------*/ 
    
    createRender("images/background_start.bmp", renderer, window, 1, 2);

    /*------------------Start Mario Bros Pannel Render----------------------------------*/ 

    createRender("images/start_pannel.bmp", renderer, window, 2, 8);

    /*-----------------All Button Render-----------------------*/

    createRender("images/start_btn.bmp", renderer, window, 5, 1);
    createRender("images/help_btn.bmp", renderer, window, 4, 1);
    createRender("images/about_btn.bmp", renderer, window, 3, 1);

    SDL_RenderPresent(renderer);
    /*----------------------------------------------------*/

    SDL_bool programme_launched = SDL_TRUE;

    while (programme_launched)
    {
        unsigned int frame_limit =  0;
        SDL_Event event;
        frame_limit = SDL_GetTicks() + FPS_LIMIT;
        SDL_LimitFPS(frame_limit);
            

        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_b:
                            printf("Vous avez appuyez sur b");
                            continue;

                        default:
                            continue; 
                    }

                case SDL_QUIT:
                    programme_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }


    /*----------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
