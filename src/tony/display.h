#pragma once

#include "data.h"
#include <SDL.h>

//Ici seront définies les constante ou seront placés les éléments
//----------------Start screen constante -------------------------------------
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066
#define BACKGROUND_X 0
#define BACKGROUND_Y 0


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


 
typedef struct VIGNETTE {
    SDL_Texture* texture; 
    SDL_Rect rectangle; 
} VIGNETTE,  *Vignette; 

enum jour {
LUNDI,
MARDI,
MERCREDI,
JEUDI,
VENDREDI,
SAMEDI,
DIMANCHE
} ;


extern void position(); 
extern VIGNETTE AddTexture(DATA * d, char* img_name,int x,int y); 
extern void Error(const char * message,SDL_Window * window, SDL_Renderer * renderer ); 
extern void SDL_LimitFPS(unsigned int limit);
extern void createStartScreen(DATA * d, VIGNETTE* vignette);
extern void displayTexture(VIGNETTE  v, DATA *d );  
extern void displayStartScreen(VIGNETTE * v,data d , char * disp_orange, char * disp_pannel);
extern int CreateMap(data d, VIGNETTE * v);
extern void displayMap(data d, VIGNETTE * v, int k);
extern void changeImage(DATA *d, char* img_name, VIGNETTE *v);
extern void MoveMap(data d, VIGNETTE *v, int k);
extern void MoveMario(VIGNETTE * v,data d , char * disp_move, char * disp_direction);
extern void CreateMario(VIGNETTE *v, DATA * d);

void BackwardStage1(VIGNETTE * v,data d);
void ForwardStage1(VIGNETTE * v,data d);
void ForwardStage2(VIGNETTE * v,data d);
void BackwardStage1(VIGNETTE * v,data d);
