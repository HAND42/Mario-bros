
#pragma once

//Define the map of our game;
typedef struct Map{

	char** body;
	int level;
	int width;
	int height;

} *Map;

typedef enum ElementType{
	BigGreenBush=1,
	SmallGreenBush=2,
	SimpleGreenBush=3,
	TripleGreenBush=4,
	DoubleGreenBush=5,
	Stairs=6,
	InterrogationPoint=10,
	Brick=11,
	SmallPipe2=20,
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

}Element;

//Function prototype
void createMap(Map *map);

