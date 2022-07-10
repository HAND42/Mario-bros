//
// Created by Hugodurand on 30/06/2022.
//
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "display.h"
#include "data.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066
#define CROSS_SIZE  70

#define FPS_LIMIT 33

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    MapGame m;

    m = MapInit(1);
    printf("bn");

    PlaceElem(&m);
    PrintMap(m);

    RenduElement background = {NULL,{0,0,0,0}, SDL_LoadBMP("images/background_start.bmp"),1,2};
    RenduElement start = {NULL,{0,0,0,0}, SDL_LoadBMP("images/start_btn.bmp"),5,1};
    RenduElement help = {NULL,{0,0,0,0}, SDL_LoadBMP("images/help_btn.bmp"),4,1};
    RenduElement about = {NULL,{0,0,0,0}, SDL_LoadBMP("images/about_btn.bmp"),3,1};
    RenduElement help_pannel = {NULL,{0,0,0,0}, SDL_LoadBMP("images/help_pannel.bmp"),1,2};
    RenduElement about_pannel = {NULL,{0,0,0,0}, SDL_LoadBMP("images/about_pannel.bmp"),1,2};
    RenduElement start_pannel = {NULL,{0,0,0,0},SDL_LoadBMP("images/start_pannel.bmp"),2,8};

    RenduElement start_screen[8]={background,start,help,about,start_pannel,help_pannel, about_pannel};

    //Lancement SDL
    if (SDL_Init(SDL_INIT_VIDEO) <0)
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

    SDL_bool programme_launched = SDL_TRUE;
    int btn =0;
    int ouvert=0;


    createStartScreen(start_screen, renderer, window);
    displayStartScreen(start_screen, renderer,window,btn);

    SDL_RenderPresent(renderer);
    //Load musique
    Mix_Music *musique =NULL; //Création d'un pointeur de type Mix_Music
    musique = Mix_LoadMUS("audio/title.mp3");; //Chargement de la musique
    if(musique == NULL)
    {
        printf("rt%s\n", Mix_GetError());
    }

    //Load sound effects
    Mix_Chunk *open_click, *close_click;
    open_click = Mix_LoadWAV("audio/open_sound.mp3");
    //close_click = Mix_LoadWAV("audio/close_sound.mp3")

    //LoadMusic();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    //PlayMusic(musique);
    Mix_VolumeMusic(MIX_MAX_VOLUME/2);
    Mix_PlayMusic(musique, -1);




    /*---------------------Event Management-------------------------------*/

    while (programme_launched)
    {
        unsigned int frame_limit =  0;
        SDL_Event event;
        frame_limit = SDL_GetTicks() + FPS_LIMIT;
        SDL_LimitFPS(frame_limit);
        displayStartScreen(start_screen, renderer,window,btn);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
                case SDL_MOUSEMOTION:
                    int x=event.motion.x;
                    int y=event.motion.y;

                    if (start_screen[1].rectangle.x<x && x<start_screen[1].rectangle.x+start_screen[1].rectangle.w  && start_screen[1].rectangle.y<y && y<start_screen[1].rectangle.y+start_screen[1].rectangle.h){
                        
                        changeImage(&(start_screen[1]), "images/start_btn_orange.bmp", renderer, window);
                        changeImage(&(start_screen[2]), "images/help_btn.bmp", renderer, window);
                        changeImage(&(start_screen[3]), "images/about_btn.bmp", renderer, window);
    
                    }
                    else if (start_screen[2].rectangle.x<x && x<start_screen[2].rectangle.x+start_screen[2].rectangle.w  && start_screen[2].rectangle.y<y && y<start_screen[2].rectangle.y+start_screen[2].rectangle.h){
                        
                        changeImage(&(start_screen[2]), "images/help_btn_orange.bmp", renderer, window);
                        changeImage(&(start_screen[1]), "images/start_btn.bmp", renderer, window);
                        changeImage(&(start_screen[3]), "images/about_btn.bmp", renderer, window);
                        
                    }
                    else if (start_screen[3].rectangle.x<x && x<start_screen[3].rectangle.x+start_screen[3].rectangle.w  && start_screen[3].rectangle.y<y && y<start_screen[3].rectangle.y+start_screen[3].rectangle.h){
                        
                        changeImage(&(start_screen[3]), "images/about_btn_orange.bmp", renderer, window);
                        changeImage(&(start_screen[1]), "images/start_btn.bmp", renderer, window);
                        changeImage(&(start_screen[2]), "images/help_btn.bmp", renderer, window);
                      
                    }
                    else{
                        changeImage(&(start_screen[1]), "images/start_btn.bmp", renderer, window);
                        changeImage(&(start_screen[2]), "images/help_btn.bmp", renderer, window);
                        changeImage(&(start_screen[3]), "images/about_btn.bmp", renderer, window);
  
                    }
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    int xx = event.button.x;
                    int yy = event.button.y;
                    
                    if (start_screen[1].rectangle.x<xx && xx<start_screen[1].rectangle.x+start_screen[1].rectangle.w  && start_screen[1].rectangle.y<yy && yy<start_screen[1].rectangle.y+start_screen[1].rectangle.h){
                        btn=3;
                        Mix_PlayChannel( -1, open_click, 0 );
                    }
                    else if (start_screen[2].rectangle.x<xx && xx<start_screen[2].rectangle.x+start_screen[2].rectangle.w  && start_screen[2].rectangle.y<yy && yy<start_screen[2].rectangle.y+start_screen[2].rectangle.h){
                        
                        btn=1; 
                        ouvert=1;
                        Mix_PlayChannel( -1, open_click, 0 );
                        printf("%d,%d\n", btn, ouvert);
                        
                    }
                    else if (start_screen[3].rectangle.x<xx && xx<start_screen[3].rectangle.x+start_screen[3].rectangle.w  && start_screen[3].rectangle.y<yy && yy<start_screen[3].rectangle.y+start_screen[3].rectangle.h){
                        
                        Mix_PlayChannel( -1, open_click, 0 );
                        btn=2; 
                        ouvert=1;
                    }

                    if(ouvert==1 && btn==1){
                        if (start_screen[5].rectangle.x+start_screen[5].rectangle.w - CROSS_SIZE<xx && xx<start_screen[5].rectangle.x+start_screen[5].rectangle.w  && start_screen[5].rectangle.y<yy && yy<start_screen[5].rectangle.y+CROSS_SIZE){
                
                            btn=0;
                            ouvert=0;
                        }
                    }
                    if(ouvert==1 && btn==2){
                        if (start_screen[6].rectangle.x+start_screen[6].rectangle.w - CROSS_SIZE<xx && xx<start_screen[6].rectangle.x+start_screen[6].rectangle.w  && start_screen[6].rectangle.y<yy && yy<start_screen[6].rectangle.y+CROSS_SIZE){

                            btn=0;
                            ouvert=0;
                        }
                    }
                    break;

                case SDL_QUIT:
                    programme_launched = SDL_FALSE;
                    break;

                    default:
                        break;
            }
        }

    }

    /*--------------------Closing Window---------------------*/
    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}


/*
Compile programm in command line :
gcc src/hugo/*.c -o bin/MarioBros -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer
bin\MarioBros.exe
*/


// case SDL_KEYDOWN:
//                     switch (event.key.keysym.sym)
//                     {
//                         case SDLK_p: 
//                             if(Mix_PausedMusic() == 1)//Si la musique est en pause
//                             {
//                                 Mix_ResumeMusic(); //Reprendre la musique
//                             }
//                             else
//                             {
//                                 Mix_PauseMusic(); //Mettre en pause la musique
//                             }
//                             break;

//                         case SDLK_BACKSPACE:
//                             Mix_RewindMusic(); //Revient au début de la musique
//                             break;
//                         case SDLK_ESCAPE:
//                             Mix_HaltMusic(); //Arrête la musique
//                             break;
//                     }
//                     break;

