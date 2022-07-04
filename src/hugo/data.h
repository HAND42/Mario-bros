
#pragma once

//Define the map of our game;
typedef struct Map{

	char** body;
	int level;
	int width;
	int height;

} *Map;

typedef enum ElementType{
	BigGreenBush;
	SmallGreenBush;
	SimpleGreenBush;
	TripleGreenBush;
	DoubleGreenBush;
	InterrogationPoint;
	Brick;


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

