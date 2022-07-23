
#pragma once
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
//Define the map of our game;

//la donnée partagée
typedef struct MapGame{

	char** body;
	int level;
	int width;
	int height;

}MapGame, *Map;

typedef struct donnée {

	SDL_Renderer *renderer; 
	SDL_Window* window; 
	MapGame map; 
}DATA, *data; 




typedef enum ElementType{
	BigGreenBush=1,
	SmallGreenBush=2,
	SimpleGreenBush=3,
	DoubleGreenBush=4,
	TripleGreenBush=5,
	Stairs=6,
	InterrogationPoint=10,
	Brick=11,
	SmallPipe=20,
	MiddlePipe=21,
	BigPipe=22,
	SmallPipeEntry=23,
	MiddlePipeEntry=24,
	BigPipeEntry=25,
	SmallPipeExit=26,
	MiddlePipeExit=27,
	BigPipeExit=28,
	Castle=30,
	Flag=40,
	Hole=50,
	BigHole=51,
}ElementType;


typedef struct Coord{
	int x;
	int y;
}Coord;

typedef struct Element{
	Coord c;
	ElementType type;
	char* s;
	int size;

}Element, *Elem;

extern Element NIVEAU[3][300] ; 


//Function prototype
extern void MapInit(int lv, MapGame * map);
extern void PutElemInMap(Map map,Elem  element, int width, int height);
extern void PlaceElem(Map map);
extern void PrintMap(Map map);

