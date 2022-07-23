//
// Created by hugod on 30/06/2022.
//
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"

extern Element NIVEAU[3][300];

int START_X =0 ; 
int START_Y =0 ; 
int START_W =434 ; 
int START_H =62 ;


 int HELP_X =0 ; 
 int HELP_Y =0 ; 
 int HELP_W =422 ; 
 int HELP_H =64 ; 


 int ABOUT_X =0 ; 
 int ABOUT_Y =0 ; 
 int ABOUT_W =443 ; 
 int ABOUT_H =63 ; 

 int HELP_PANNEL_X =0 ; 
 int HELP_PANNEL_Y =0 ; 
 int HELP_PANNEL_W =766 ; 
 int HELP_PANNEL_H =475 ; 


 int ABOUT_PANNEL_X =0 ; 
 int ABOUT_PANNEL_Y =0 ; 
 int ABOUT_PANNEL_W =677 ; 
 int ABOUT_PANNEL_H =506 ; 

 int START_PANNEL_W =538 ; 
 int START_PANNEL_H =264 ; 
 int START_PANNEL_X =0 ; 
 int START_PANNEL_Y =0; 

 int POS_X = 65;
 int POS_Y = 48;
 int MARIO_SIZE = 25;

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1066

#define FPS_LIMIT 33


void position(){
     START_PANNEL_X=(WINDOW_WIDTH-START_PANNEL_W)/2; 
     START_PANNEL_Y=(WINDOW_HEIGHT*0.02);

    START_X =(WINDOW_WIDTH-START_W)/2;
    START_Y=START_PANNEL_Y+(WINDOW_HEIGHT*0.002)+ START_PANNEL_H;

    HELP_X =(WINDOW_WIDTH-HELP_W)/2;
    HELP_Y=START_Y+(WINDOW_HEIGHT*0.002)+ START_H ; 

    ABOUT_X =(WINDOW_WIDTH-ABOUT_W)/2;
    ABOUT_Y=HELP_Y+(WINDOW_HEIGHT*0.002)+ HELP_H ; 

    POS_Y = WINDOW_HEIGHT - POS_Y - MARIO_SIZE;

}


void Error(const char * message,SDL_Window * window, SDL_Renderer * renderer ){
    if(renderer!=NULL){
        SDL_DestroyRenderer(renderer); 
    }
    if(window!=NULL){
        SDL_DestroyWindow(window); 
    }
    
     
    SDL_Log("ERREUR: %s > %s \n ", message, SDL_GetError()); 
    SDL_Quit(); 

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

//cette fonction a pour role de placer une texture aux coordonées x et y
// l'argument data est la donnée partagée, l'argument img_name est le nom de l'image.
VIGNETTE AddTexture(DATA *d, char* img_name,int x,int y){
    
    // on crée une surface
    SDL_Surface *image=NULL; 
    image = SDL_LoadBMP(img_name);
    if(image==NULL)
    {   
        Error(" Création of surface failed jh",d->window,d->renderer);
        
    }
     
    //on crée une texture avec l'image
    SDL_Texture* texture=NULL;
    texture = SDL_CreateTextureFromSurface(d->renderer,image);
    SDL_FreeSurface(image);
    if(texture==NULL)
    {   printf("%s \n ",img_name ); 
        Error(" Création of texture failed g",d->window,d->renderer);
    }

  
// on crée un rectangle
   SDL_Rect rectangle; 
    
    // on charge la texture en mémoire
    if (SDL_QueryTexture(texture,NULL,NULL,&rectangle.w,& rectangle.h)!=0 ){
        Error(" loading of texture failed",d->window,d->renderer);
    }

    rectangle.x=x; 
    rectangle.y=y; 
   
    //on créer l'objet vignette que l'on va renoyer 
    VIGNETTE v={texture, rectangle};
    return v; 

}

// cette fonction a pour role d'afficher la map
int CreateMap(data d, VIGNETTE * v){
    char chemin[200]="images/Element/";
    int k = 0;

    //on affiche tout d'abord le ciel et le sol.
    strcat(chemin, "sky.bmp"); 
    v[k]=AddTexture(d,chemin,0,0);
    k++;
    strcpy(chemin,"images/Element/"); 

    //on affiche ensuite le sol
    strcat(chemin, "alltheground.bmp"); 
    v[k]=AddTexture(d,chemin,0,WINDOW_HEIGHT-50);
    
    //on parcourt le tableau element et on affiche 1 à 1 les trucs;
    int lenght = sizeof(NIVEAU[d->map.level -1])/sizeof(Element);
    for(int i=0; i<lenght; i++){
        k++;
        strcpy(chemin,"images/Element/");
        Element element = NIVEAU[d->map.level -1][i];  
        int X=element.c.x*25; 
        int Y= WINDOW_HEIGHT- element.c.y*25; 
        switch(element.type){

            case Stairs :

                if (strcmp(element.s,"up")==0){
                    strcat(chemin, "StairsUp4.bmp");
                    v[k]=AddTexture(d,chemin,X,Y);
                    v[k].rectangle.y -=v[k].rectangle.h;

                }
                else{
                    strcat(chemin, "StairsDown4.bmp");
                    v[k]=AddTexture(d,chemin,X,Y);
                    v[k].rectangle.y -=v[k].rectangle.h;
                }
                // strcat(chemin, "Stairs.bmp");
                // if (strcmp(element.s,"up")==0){ 
                //     for(int i=0; i<element.size;i++){
                //         for(int j=i;j<element.size;j++ ){
                //             v[k]=AddTexture(d,chemin,X+j*25,Y+i*25);
                //             printf("(%d, %d)",X+j*25,Y+i*25);
                //             v[k].rectangle.y -=v[k].rectangle.h;
                //             k++;
                //         }
                //     }
                //     printf("end stairs up");
                // }
                // else{
                //     for(int i=element.size-1; i>=0;i--){
                //         for(int j=0;j<element.size -i;j++){
                //             v[k]=AddTexture(d,chemin,X+j*25,Y+i*25);
                //             printf("(%d, %d)",X+j*25,Y+i*25);
                //             v[k].rectangle.y -=v[k].rectangle.h;
                //             k++;
                //         }
                //     }
                //     printf("end stairs down");
                // }
                
                break;

            case BigGreenBush:
                strcat(chemin, "BigGreenBush.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y);
                v[k].rectangle.y -=v[k].rectangle.h;

                break;

            case SmallGreenBush:
                strcat(chemin, "SmallGreenBush.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;

            case SimpleGreenBush:
                strcat(chemin, "SimpleGreenBush.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;

            case DoubleGreenBush:
                strcat(chemin, "DoubleGreenBush.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case TripleGreenBush:
                strcat(chemin, "TripleGreenBush.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case Hole:
                strcat(chemin, "Hole.bmp");
                for(int i=0; i<2; i++){
                    for(int j=0; j<2; j++){
                        v[k]=AddTexture(d,chemin,X+i,Y+j);
                        v[k].rectangle.y -=v[k].rectangle.h;
                        k++;
                    }
                }
                

                break;
            case BigHole:
                 strcat(chemin, "Hole.bmp");
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        v[k]=AddTexture(d,chemin,X+i,Y+j); 
                        v[k].rectangle.y -=v[k].rectangle.h;
                        k++;
                    }
                }
                break;
            case SmallPipe:
                strcat(chemin, "SmallPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case SmallPipeEntry:
                strcat(chemin, "SmallPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case SmallPipeExit:
                strcat(chemin, "SmallPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case BigPipe:
                strcat(chemin, "BigPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case BigPipeEntry:
                strcat(chemin, "BigPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case BigPipeExit:
                strcat(chemin, "BigPipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y);
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case MiddlePipe:
                strcat(chemin, "MiddlePipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case MiddlePipeEntry:
                strcat(chemin, "MiddlePipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case MiddlePipeExit:
                strcat(chemin, "MiddlePipe.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case InterrogationPoint:
                strcat(chemin, "InterrogationPoint.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case Brick:
                strcat(chemin, "Brick.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y);
                v[k].rectangle.y -=v[k].rectangle.h; 
                break;
            case Castle:
                strcat(chemin, "Castle.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;
            case Flag:
                strcat(chemin, "Flag.bmp"); 
                v[k]=AddTexture(d,chemin,X,Y); 
                v[k].rectangle.y -=v[k].rectangle.h;
                break;

            default:
                break;
        }

    }
    return k;
}

void displayMap(data d, VIGNETTE * v, int k){
    for (int i = 0 ; i < k; i++)
    {
        // printf("%d,%d,%d\n", i, v[i].rectangle.x, v[i].rectangle.y);
        displayTexture(v[i],d);
    }
}   
    

void MoveMap(data d, VIGNETTE *v, int k){
    for (int i = 0 ; i < k; i++)
    {
        v[i].rectangle.x -=25;
    }
}


//cette fonction a pour role de changer l'image d'une texture
void changeImage(DATA *d, char* img_name, VIGNETTE *v){
    SDL_Surface *image =NULL; 
    image= SDL_LoadBMP(img_name);
    v->texture = SDL_CreateTextureFromSurface(d->renderer, image);

    if (v->texture ==NULL)
        Error(" Création of texture failed",d->window,d->renderer);
}

//cette fonction a pour role d'afficher le start screen, le tableau SDL_Texture est un paramètre résultat contenant un tableau
//de texture.
void createStartScreen(DATA * d, VIGNETTE * vignette){

    vignette[0]=AddTexture(d,"images/background_start.bmp",BACKGROUND_X,BACKGROUND_Y); 
    vignette[1]=AddTexture(d,"images/start_btn.bmp",START_X,START_Y);
    vignette[2]=AddTexture(d,"images/help_btn.bmp",HELP_X,HELP_Y);
    vignette[3]=AddTexture(d,"images/about_btn.bmp",ABOUT_X,ABOUT_Y);
    vignette[4]=AddTexture(d,"images/start_pannel.bmp",START_PANNEL_X,START_PANNEL_Y);
    vignette[5]=AddTexture(d,"images/help_pannel.bmp",HELP_PANNEL_X,HELP_PANNEL_Y);
    vignette[6]=AddTexture(d,"images/about_pannel.bmp",ABOUT_PANNEL_X,ABOUT_PANNEL_Y);

    
    
}

void displayTexture(VIGNETTE  v, DATA *d ){ 
    if (SDL_RenderCopy(d->renderer, v.texture, NULL, &(v.rectangle))!=0){
        printf("%d / %d", v.rectangle.x/25, v.rectangle.y/25);
        Error(" RenderCopy failed",d->window,d->renderer);

        
    }
}
 

void displayStartScreen(VIGNETTE *v,data d , char * disp_orange, char * disp_pannel){
    if (!strcmp(disp_orange,"start_orange")){
        changeImage(d,"images/help_btn.bmp", &v[2]);
        changeImage(d,"images/about_btn.bmp", &v[3]);
        changeImage(d,"images/start_btn_orange.bmp", &v[1]);
    }
    else if (!strcmp(disp_orange,"help_orange")){
        changeImage(d,"images/help_btn_orange.bmp", &v[2]);
        changeImage(d,"images/about_btn.bmp", &v[3]);
        changeImage(d,"images/start_btn.bmp",&v[1]);
    }
    else if (!strcmp(disp_orange,"about_orange")){
        changeImage(d,"images/help_btn.bmp", &v[2]);
        changeImage(d,"images/about_btn_orange.bmp", &v[3]);
        changeImage(d,"images/start_btn.bmp", &v[1]);
    }

    else{
        changeImage(d,"images/help_btn.bmp", &v[2]);
        changeImage(d,"images/about_btn.bmp", &v[3]);
        changeImage(d,"images/start_btn.bmp", &v[1]);
    }

    for (int i = 0 ; i < 5 ; i++)
    {
        displayTexture(v[i],d);
    }
   
    if (!strcmp(disp_pannel,"about")){
        displayTexture(v[6],d);

    }
     else if (!strcmp(disp_pannel,"help")){
        displayTexture(v[5],d);

    }
    else if (!strcmp(disp_pannel,"afficher")){
    }
}

void CreateMario(VIGNETTE * vignette, DATA * d){

    vignette[0]=AddTexture(d,"images/Mario/littlemarioturnright.bmp",POS_X,POS_Y); 
    vignette[1]=AddTexture(d,"images/Mario/littlemariofd1.bmp",POS_X,POS_Y); 
    vignette[2]=AddTexture(d,"images/Mario/littlemariofd2.bmp",POS_X,POS_Y); 
    vignette[3]=AddTexture(d,"images/Mario/littlemariolookright.bmp",POS_X,POS_Y); 
    vignette[4]=AddTexture(d,"images/Mario/littlemarioturnleft.bmp",POS_X,POS_Y); 
    vignette[5]=AddTexture(d,"images/Mario/littlemariobd1.bmp",POS_X,POS_Y); 
    vignette[6]=AddTexture(d,"images/Mario/littlemariobd2.bmp",POS_X,POS_Y); 
    vignette[7]=AddTexture(d,"images/Mario/littlemariolookleft.bmp",POS_X,POS_Y); 

}

void ForwardStage1(VIGNETTE * v,data d){
    displayTexture(v[1],d);
    for (int i = 0 ; i < 7; i++)
    {
        v[i].rectangle.x +=5;
    }
}

void ForwardStage2(VIGNETTE * v,data d){
    displayTexture(v[2],d);
    for (int i = 0 ; i < 7; i++)
    {
        v[i].rectangle.x +=5;
    }
}

void BackwardStage1(VIGNETTE * v,data d){
    displayTexture(v[5],d);
}

void BackwardStage2(VIGNETTE * v,data d){
    displayTexture(v[6],d);
}

void MoveMario(VIGNETTE * v,data d , char * disp_move, char * disp_direction){
    if (!strcmp(disp_direction,"right")){
        displayTexture(v[0],d);
    }
     if (!strcmp(disp_direction,"left")){
        displayTexture(v[4],d);
    }
    if (!strcmp(disp_move,"move_right")){
        displayTexture(v[1],d);
        SDL_Delay(200);
        displayTexture(v[2],d);
        
    }

}