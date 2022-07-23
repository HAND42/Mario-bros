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
VIGNETTE AddTexture(DATA *d, char* img_name){
    
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
    SDL_Rect rectangle[1] = {};
    VIGNETTE v={texture, rectangle}; 
    return v ; 
}



void AddRect(DATA * d,VIGNETTE * v, int x , int y){

  
// on crée un rectangle
   SDL_Rect rectangle; 
   printf("eb");
    
    // on charge la texture en mémoire
    if (SDL_QueryTexture(v->texture,NULL,NULL,&rectangle.w,& rectangle.h)!=0 ){
        Error(" loading of texture failed",d->window,d->renderer);
    }
    
    printf("fghj");

    rectangle.x=x; 
    rectangle.y=y;


    int lght = sizeof(v->rectangle)/sizeof(SDL_Rect);
    printf("%d", lght);
    (v->rectangle[lght])=rectangle; 
    lght++;
    printf("%d, %d, mdl", v->rectangle[0].x,v->rectangle[0].y);
    printf("alllllllez\n");
   
   }
    


// cette fonction a pour role d'afficher la map
void CreateMap(data d, VIGNETTE * v){

    char chemin[200]="images/Element/";
    

    //on affiche tout d'abord le ciel et le sol.
    strcat(chemin, "sky.bmp"); 
    v[0]=AddTexture(d,chemin);
    AddRect(d,&v[0],0,WINDOW_HEIGHT); 
    

    strcpy(chemin,"images/Element/"); 

    //on affiche ensuite le sol
    strcat(chemin, "alltheground.bmp"); 
    v[1]=AddTexture(d,chemin);
    AddRect(d,&v[1],0,2*WINDOW_HEIGHT-50); 
    

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "Stairs.bmp"); 
    v[2]=AddTexture(d,chemin);


     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "BigGreenBush.bmp"); 
    v[3]=AddTexture(d,chemin);

     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "SmallGreenBush.bmp"); 
    v[4]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "SimpleGreenBush.bmp"); 
    v[5]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "DoubleGreenBush.bmp"); 
    v[6]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "TripleGreenBush.bmp"); 
    v[7]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "Hole.bmp"); 
    v[8]=AddTexture(d,chemin);

     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "SmallPipe.bmp"); 
    v[9]=AddTexture(d,chemin);

     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "BigPipe.bmp"); 
    v[10]=AddTexture(d,chemin);

     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "MiddlePipe.bmp"); 
    v[11]=AddTexture(d,chemin);

     strcpy(chemin,"images/Element/"); 
    strcat(chemin, "InterrogationPoint.bmp"); 
    v[12]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "Brick.bmp"); 
    v[13]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "Castle.bmp"); 
    v[14]=AddTexture(d,chemin);

    strcpy(chemin,"images/Element/"); 
    strcat(chemin, "Flag.bmp"); 
    v[15]=AddTexture(d,chemin);

    
    //on parcourt le tableau element et on affiche 1 à 1 les trucs;
    int lenght = sizeof(NIVEAU[d->map.level -1])/sizeof(Element);
    for(int i=0; i<lenght; i++){
        strcpy(chemin,"images/Element/");
        Element element = NIVEAU[d->map.level -1][i];  
        int X=element.c.x*25; 
        int Y= WINDOW_HEIGHT- element.c.y*25; 
        switch(element.type){

            case Stairs :

                
                strcat(chemin, "Stairs.bmp");
                if (strcmp(element.s,"up")==0){ 
                    for(int i=0; i<element.size;i++){
                        for(int j=i;j<element.size;j++ ){
                            AddRect(d,&v[2],X+j*25,Y+i*25);
                            // printf("(%d, %d)",X+j*25,Y+i*25);
                          
                        }
                    }
                    printf("end stairs up");
                }
                else{
                    for(int i=element.size-1; i>=0;i--){
                        for(int j=0;j<element.size -i;j++){
                            AddRect(d, &v[2],X+j*25,Y+i*25);
                            // printf("(%d, %d)",X+j*25,Y+i*25);
                          
                        }
                    }
                    // printf("end stairs down");
                }
                
                break;

            case BigGreenBush:
                AddRect(d,&v[3],X,Y);
               

                break;

            case SmallGreenBush:
                AddRect(d,&v[4],X,Y);
                break;

            case SimpleGreenBush:
                AddRect(d,&v[5],X,Y);
                break;

            case DoubleGreenBush:
                AddRect(d,&v[6],X,Y);
                break;
            case TripleGreenBush:
                AddRect(d,&v[7],X,Y);
                
                break;
            case Hole:
                for(int i=0; i<2; i++){
                    for(int j=0; j<2; j++){
                        AddRect(d,&v[8],X+i,Y+j);
                        
                    }
                }
                

                break;
            case BigHole:
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        AddRect(d,&v[8],X+i,Y+j); 
                      
                    }
                }
                break;
            case SmallPipe:
            case SmallPipeEntry:
            case SmallPipeExit:
                AddRect(d,&v[9],X,Y); 
                break;
            case BigPipe:
            case BigPipeEntry:
            case BigPipeExit: 
                AddRect(d,&v[10],X,Y);
                
                break;
            case MiddlePipe:
            case MiddlePipeEntry:
            case MiddlePipeExit:
                
                AddRect(d,&v[11],X,Y); 
                
                break;
            case InterrogationPoint:
               
                AddRect(d,&v[12],X,Y);
                
                break;
            case Brick:
                 
                AddRect(d,&v[13],X,Y);
                
                break;
            case Castle:
                
                AddRect(d,&v[14],X,Y); 
                
                break;
            case Flag:
               
                AddRect(d,&v[15],X,Y); 
               
                break;

            default:
                break;
        }

    }
   
}

void displayMap(data d, VIGNETTE * v){
    int lenght = sizeof(v)/sizeof(VIGNETTE);
    printf("%d", lenght); 
    for (int i = 0 ; i < lenght; i++)
    {
        int lenght1 = sizeof(v[i].rectangle)/sizeof(SDL_Rect);
        for(int j=0; j< lenght1;j++){
        // printf("%d,%d,%d\n", i, v[i].rectangle.x, v[i].rectangle.y);
        displayTexture(v[i].texture,(v[i].rectangle)[j] ,d);
    }
}
}   
    

void MoveMap(data d, VIGNETTE *v){
    int lenght = sizeof(v)/sizeof(VIGNETTE);
    for (int i = 0 ; i < lenght; i++)
    {
        int lenght1 = sizeof(v[i].rectangle)/sizeof(SDL_Rect);
        for(int j=0; j< lenght1;j++){
         (v[i].rectangle)[j].x -=25;
       
    }
}
    // for (int i = 0 ; i < 70; i++)
    // {
    //     v[i].rectangle.x -=25;
    // }
}


//cette fonction a pour role de changer l'image d'une texture
void changeImage(DATA *d, char* img_name, VIGNETTE *v){
    printf("je rentre dans changeImage\n");
    SDL_Surface *image =NULL; 
    image= SDL_LoadBMP(img_name);
    v->texture = SDL_CreateTextureFromSurface(d->renderer, image);

    if (v->texture ==NULL)
        Error(" Création of texture failed",d->window,d->renderer);
}

//cette fonction a pour role d'afficher le start screen, le tableau SDL_Texture est un paramètre résultat contenant un tableau
//de texture.
void createStartScreen(DATA * d, VIGNETTE * vignette){

    printf("je rentre dans createStartScreen\n");

    vignette[0]=AddTexture(d,"images/background_start.bmp");
    printf("Ajoute\n");
    AddRect(d,&vignette[0],BACKGROUND_X,BACKGROUND_Y);
    printf("%d\n", ((vignette[0].rectangle)[0]).x );
    vignette[1]=AddTexture(d,"images/start_btn.bmp");
     AddRect(d,&vignette[1],START_X,START_Y);
    vignette[2]=AddTexture(d,"images/help_btn.bmp");
     AddRect(d,&vignette[2],HELP_X,HELP_Y);
    vignette[3]=AddTexture(d,"images/about_btn.bmp");
     AddRect(d,&vignette[3],ABOUT_X,ABOUT_Y);
    vignette[4]=AddTexture(d,"images/start_pannel.bmp");
     AddRect(d,&vignette[4],START_PANNEL_X,START_PANNEL_Y);
    vignette[5]=AddTexture(d,"images/help_pannel.bmp");
     AddRect(d,&vignette[5],HELP_PANNEL_X,HELP_PANNEL_Y);
    vignette[6]=AddTexture(d,"images/about_pannel.bmp");
     AddRect(d,&vignette[6],ABOUT_PANNEL_X,ABOUT_PANNEL_Y);


    
    
}

void displayTexture(SDL_Texture* texture, SDL_Rect  rectangle, DATA *d ){ 
    if (SDL_RenderCopy(d->renderer, texture, NULL, &(rectangle))!=0){
        printf("%d / %d", rectangle.x/25, rectangle.y/25);
        Error(" RenderCopy failed",d->window,d->renderer);
    }

    printf("je sors de displayTexture\n");

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
        displayTexture((v[i].texture), (v[i].rectangle)[0],d);
        printf("%d\n", (((v[i].rectangle)[0]).y));
    }
   
    if (!strcmp(disp_pannel,"about")){
        displayTexture((v[6].texture), (v[6].rectangle)[0],d);

    }
     else if (!strcmp(disp_pannel,"help")){
        displayTexture((v[5].texture), (v[5].rectangle)[0],d);

    }
    else if (!strcmp(disp_pannel,"afficher")){
    }
}

void CreateMario(VIGNETTE * vignette, DATA * d){

    vignette[0]=AddTexture(d,"images/Mario/littlemarioturnright.bmp"); 
    AddRect(d,&vignette[0],POS_X,POS_Y); 
    vignette[1]=AddTexture(d,"images/Mario/littlemariofd1.bmp"); 
    AddRect(d,&vignette[1],POS_X,POS_Y);
    vignette[2]=AddTexture(d,"images/Mario/littlemariofd2.bmp"); 
    AddRect(d,&vignette[2],POS_X,POS_Y);

    vignette[3]=AddTexture(d,"images/Mario/littlemariolookright.bmp"); 
     AddRect(d,&vignette[3],POS_X,POS_Y);
    vignette[4]=AddTexture(d,"images/Mario/littlemarioturnleft.bmp"); 
     AddRect(d,&vignette[4],POS_X,POS_Y);
    vignette[5]=AddTexture(d,"images/Mario/littlemariobd1.bmp"); 
     AddRect(d,&vignette[5],POS_X,POS_Y);
    vignette[6]=AddTexture(d,"images/Mario/littlemariobd2.bmp"); 
     AddRect(d,&vignette[6],POS_X,POS_Y);
    vignette[7]=AddTexture(d,"images/Mario/littlemariolookleft.bmp"); 
     AddRect(d,&vignette[7],POS_X,POS_Y);

}

// void ForwardStage1(VIGNETTE * v,data d){
//     displayTexture(v[1],d);
//     for (int i = 0 ; i < 7; i++)
//     {
//         v[i].rectangle.x +=5;
//     }
// }

// void ForwardStage2(VIGNETTE * v,data d){
//     displayTexture(v[2],d);
//     for (int i = 0 ; i < 7; i++)
//     {
//         v[i].rectangle.x +=5;
//     }
// }

// void BackwardStage1(VIGNETTE * v,data d){
//     displayTexture(v[5],d);
// }

// void BackwardStage2(VIGNETTE * v,data d){
//     displayTexture(v[6],d);
// }

// void MoveMario(VIGNETTE * v,data d , char * disp_move, char * disp_direction){
//     if (!strcmp(disp_direction,"right")){
//         displayTexture(v[0],d);
//     }
//      if (!strcmp(disp_direction,"left")){
//         displayTexture(v[4],d);
//     }
//     if (!strcmp(disp_move,"move_right")){
//         displayTexture(v[1],d);
//         SDL_Delay(200);
//         displayTexture(v[2],d);
        
//     }

//}