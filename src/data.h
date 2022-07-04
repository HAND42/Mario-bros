
#pragma once

//Define the map of our game;
typedef struct Map{

	char** body;
	int level;
	int width;
	int height;

} *Map;

typedef enum BushType{
	BigGreenBush;
	SmallGreenBush;
	SimpleGreenBush;
	TripleGreenBush;
	DoubleGreenBush;

}BushType;


typedef struct Coord{
	int x;
	int y;
	BushType type;

};


//Function prototype
void createMap(Map *map);

