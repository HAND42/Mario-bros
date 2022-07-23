
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "data.h"
#include <string.h>
//#include <SDL_mixer.h>

extern int START_X ; 
extern int START_Y ; 
extern int START_W ; 
extern int START_H ;

extern int HELP_X ; 
extern int HELP_Y ; 
extern int HELP_W ; 
extern int HELP_H ; 


extern int ABOUT_X ; 
extern int ABOUT_Y ; 
extern int ABOUT_W ; 
extern int ABOUT_H ; 

extern int HELP_PANNEL_X ; 
extern int HELP_PANNEL_Y ; 
extern int HELP_PANNEL_W ; 
extern int HELP_PANNEL_H ; 


extern int ABOUT_PANNEL_X ; 
extern int ABOUT_PANNEL_Y ; 
extern int ABOUT_PANNEL_W ; 
extern int ABOUT_PANNEL_H ; 

extern int START_PANNEL_X ; 
extern int START_PANNEL_Y ; 
extern int START_PANNEL_W ; 
extern int START_PANNEL_H ; 


#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066
#define CROSS_SIZE  70
#define FPS_LIMIT 33

int main(int argc, char **argv)
{
    //Création of shared data structure
     
     
    SDL_Window * window = NULL; 
    SDL_Renderer * renderer = NULL;
    MapGame map={NULL,0,0,0};
    DATA d={renderer, window, map};
    
    position();
    MapInit(1, &(d.map)); 
    PlaceElem(&(d.map));
    

    VIGNETTE vignette[10]={};
    VIGNETTE level1[500]={};
    VIGNETTE mario[10]={};

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        
        Error("SDL initialization failed",NULL, NULL);
    }

    //Creation fenetre + rendu 
    if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE, &(d.window), &(d.renderer))!=0)
       Error(" Création of renderer and window failed",d.window,d.renderer);

    /*
    Creation of the icon and title of the window
    */
    SDL_SetWindowTitle(d.window, "MarioBrosGame");
    SDL_Surface *mario_bros_icon = NULL;
    mario_bros_icon = SDL_LoadBMP("images/mario_bros_icon.bmp");
    if (mario_bros_icon ==NULL){
        Error("Loading the mario icon failed",d.window,d.renderer);
    }
    SDL_SetWindowIcon(d.window, mario_bros_icon);
    SDL_FreeSurface( mario_bros_icon);


    SDL_bool programme_launched = SDL_TRUE;
    char disp_orange[25]="" ;
    char disp_pannel[25]=""; 
    char disp_move[25]="";
    char disp_direction[25]="right";
    int GameStarted=0;
    int k=0;

     //Create start screen and display it for the first time
    createStartScreen(&d, vignette); 
    displayStartScreen(vignette ,&d ,"", "help_c");
    SDL_RenderPresent(d.renderer);

    
    // Mix_Music *musique =NULL; //Création d'un pointeur de type Mix_Music
    // musique = Mix_LoadMUS("audio/title.mp3");; //Chargement de la musique
    // if(musique == NULL)
    // {
    //     printf("rt%s\n", Mix_GetError());
    // }

    // //Load sound effects
    // Mix_Chunk *open_click, *close_click;
    // open_click = Mix_LoadWAV("audio/open_sound.mp3");
    // //close_click = Mix_LoadWAV("audio/close_sound.mp3")

    // //LoadMusic();
    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    // //PlayMusic(musique);
    // Mix_VolumeMusic(MIX_MAX_VOLUME/2);
    // Mix_PlayMusic(musique, -1);


    /*---------------------Event Management-------------------------------*/
    while (programme_launched)
    {
        unsigned int frame_limit =  0;
        SDL_Event event;
        frame_limit = SDL_GetTicks() + FPS_LIMIT;
        SDL_LimitFPS(frame_limit);
        if (!GameStarted){
            while(SDL_PollEvent(&event))
            {
                switch(event.type)
                {
                    case SDL_MOUSEMOTION:
                        int x=event.motion.x;
                        int y=event.motion.y;

                        if (START_X<x && x<START_X+START_W  && START_Y<y && y<START_Y+START_H ){
                            strcpy(disp_orange,"start_orange"); 
                            
                        }
                        else if (HELP_X<x && x<HELP_X+HELP_W && HELP_Y<y && y<HELP_Y+HELP_H){
                            
                            strcpy(disp_orange,"help_orange"); 
                            
                        }
                        else if (ABOUT_X<x && x<ABOUT_X+ABOUT_W  && ABOUT_Y<y && y<ABOUT_Y+ABOUT_H){
                            
                            strcpy(disp_orange,"about_orange"); 
                          
                        }
                        else{
                             
                            strcpy(disp_orange,""); 
                        }
                        SDL_RenderClear(d.renderer);
                        displayStartScreen(vignette ,&d , disp_orange, disp_pannel); 
                        SDL_RenderPresent(d.renderer);
                        break;

                    case SDL_MOUSEBUTTONDOWN:
                        int xx = event.button.x;
                        int yy = event.button.y;
                        
                        if (START_X<xx && xx<START_X+START_W  && START_Y<yy && yy<START_Y+START_H){
                            GameStarted =1;
                            k = CreateMap(&d, level1);
                            printf("%d\n", k);
                            CreateMario(mario ,&d);
                            strcpy(disp_pannel,"afficher"); 
                            SDL_RenderClear(d.renderer);
                            displayMap(&d, level1, k);
                            SDL_RenderPresent(d.renderer);
                            //Mix_PlayChannel( -1, open_click, 0 );
                        }
                        else if (HELP_X<xx && xx<HELP_X+HELP_W  && HELP_Y<yy && yy<HELP_Y+HELP_H ){
                            
                            strcpy(disp_pannel, "help"); 
                            //Mix_PlayChannel( -1, open_click, 0 );
                            
                            
                        }
                        else if (ABOUT_X<xx && xx<ABOUT_X+HELP_W  && ABOUT_Y<yy && yy<ABOUT_Y+ABOUT_H){
                            strcpy(disp_pannel ,"about");
                            // Mix_PlayChannel( -1, open_click, 0 );
                            
                        }

                        if(!strcmp(disp_pannel,"help")){
                            if (HELP_PANNEL_X+HELP_PANNEL_W - CROSS_SIZE<xx && xx<HELP_PANNEL_X+HELP_PANNEL_W  && HELP_PANNEL_Y<yy && yy<HELP_PANNEL_Y+CROSS_SIZE){
                                strcpy(disp_pannel,"help_c");
                              
                            }
                        }
                        if(!strcmp(disp_pannel,"about")){
                            if (ABOUT_PANNEL_X+ABOUT_PANNEL_W - CROSS_SIZE<xx && xx<ABOUT_PANNEL_X+ABOUT_PANNEL_W  && ABOUT_PANNEL_Y<yy && yy<ABOUT_PANNEL_Y+CROSS_SIZE){
                                strcpy(disp_pannel,"about_c");
                                
                            }
                        }
                        if (!GameStarted){
                            SDL_RenderClear(d.renderer);
                            displayStartScreen(vignette ,&d , disp_orange, disp_pannel); 
                            SDL_RenderPresent(d.renderer);
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
        else{
            while(SDL_PollEvent(&event)){

                switch(event.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        int xx = event.button.x;
                        int yy = event.button.y;
                        SDL_RenderClear(d.renderer);
                        displayMap(&d, level1, k);
                        SDL_RenderPresent(d.renderer);
                        break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym){
                            case SDLK_TAB:
                                SDL_RenderClear(d.renderer);
                                MoveMap(&d, level1, k);
                                displayMap(&d, level1, k);
                                SDL_RenderPresent(d.renderer);
                                break;

                            case SDLK_RIGHT:
                                strcpy(disp_direction ,"right");

                                SDL_RenderClear(d.renderer);
                                displayMap(&d, level1, k);
                                ForwardStage1(mario, &d);
                                SDL_RenderPresent(d.renderer);

                                SDL_Delay(200);

                                SDL_RenderClear(d.renderer);
                                displayMap(&d, level1, k);
                                ForwardStage2(mario, &d);
                                SDL_RenderPresent(d.renderer);

                                SDL_Delay(200);

                                break;

                            case SDLK_LEFT:
                                strcpy(disp_move ,"move_left");
                                strcpy(disp_direction ,"left");
                                break;

                        }
                        break;
                    case SDL_QUIT:
                        programme_launched = SDL_FALSE;
                        break;

                    default:
                        break; 
                }
                strcpy(disp_move,"");
                SDL_RenderClear(d.renderer);
                displayMap(&d, level1, k);
                MoveMario(mario ,&d , "", disp_direction);
                SDL_RenderPresent(d.renderer);

            }
        }

    }

    /*--------------------Closing Window---------------------*/
    // Mix_CloseAudio();
    SDL_DestroyRenderer(d.renderer);
    SDL_DestroyWindow( d.window);
    SDL_Quit();

    return 0;
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

