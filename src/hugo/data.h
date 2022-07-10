
#pragma once

//Define the map of our game;
typedef struct MapGame{

	char** body;
	int level;
	int width;
	int height;

}MapGame, *Map;

typedef enum ElementType{
	BigGreenBush=1,
	SmallGreenBush=2,
	SimpleGreenBush=3,
	TripleGreenBush=4,
	DoubleGreenBush=5,
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

//Function prototype
MapGame MapInit(int lv);
void PutElemInMap(Map map,Elem  element, int width, int height);
void PlaceElem(Map map);
void PrintMap(MapGame map);

