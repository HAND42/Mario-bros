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

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    Rendu background = {NULL, NULL, SDL_LoadBMP("images/background_start.bmp")};


    //Lancement SDL
    if (SDL_Init(SDL_INIT_VIDEO) !=0)
        ExitWithError("Initialisation SDL");

    //Creation fenetre + rendu 
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &window, &renderer)!=0)
        ExitWithError("Impossible de créer la fenetre et le rendu");

    // le titre de la fenêtre est la chaîne de caractère passée en deuxième argument
    SDL_SetWindowTitle(window, "MarioBrosGame");

    // ajoute une icône à la fenêtre
    SDL_Surface *mario_bros_icon = NULL;
    mario_bros_icon = SDL_LoadBMP("images/mario_bros_icon.bmp");

    if (mario_bros_icon ==NULL){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        ExitWithError("Impossible de charger l'image");
    }

    SDL_SetWindowIcon(window, mario_bros_icon);

    /*------------------Background Landscape Start Render----------------------------------*/ 
    
    createRender(&background, renderer, window, 1, 2);

    /*------------------Start Mario Bros Pannel Render----------------------------------*/ 

    //createRender("images/start_pannel.bmp", renderer, window, 2, 8);

    /*-----------------All Button Render-----------------------*/
    // start = createRender("images/start_btn.bmp", renderer, window, 5, 1);
    // help = createRender("images/help_btn.bmp", renderer, window, 4, 1);
    // about = createRender("images/about_btn.bmp", renderer, window, 3, 1);

    SDL_RenderPresent(renderer);


    /*---------------------Event Management-------------------------------*/

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
                case SDL_MOUSEMOTION:
                    int x=event.motion.x;
                    int y=event.motion.y;
                    printf("%d,%d\n", x, y);

                    // int start_x_min = (WINDOW_WIDTH - rectangle.w)/2;
                    // int start_y_min = (WINDOW_HEIGHT - 5*rectangle.h);
                    // int start_x_max = (WINDOW_WIDTH - rectangle.w)/2 + rectangle.w;
                    // int start_y_max = (WINDOW_HEIGHT - 5*rectangle.h) + rectangle.h;

                    // if (start_x_min<x && x<start_x_max  && start_y_min<y && y<start_y_max){
                    //     rectangle.x = 0;
                    //     rectangle.y =0;
                    //     printf("%d", rectangle.x);
                    //     //createRender("images/start_btn_orange.bmp", renderer, window, 5, 1);
                    //     SDL_RenderPresent(renderer);
                    // }




                        
                    //SDL_MapRGB(sur->format, 0x00,0x00,0xff);
                    break;

                    /* Change the all screen in white
                    SDL_Surface* screen = NULL;
                    screen = SDL_GetWindowSurface(window);
                    SDL_LockSurface(screen);
                    SDL_memset(screen->pixels, 255, screen->h *screen->pitch);
                    SDL_UnlockSurface(screen);
                    SDL_UpdateWindowSurface(window);
                    */

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

    /*--------------------Closing Window---------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}


/*
Compile programm in command line :
gcc src/*.c -o bin/MarioBros -I include -L lib -lmingw32 -lSDL2main -lSDL2
bin\MarioBros.exe
*/
