#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Element NIVEAU[1][300] =  {{{{0,3}, BigGreenBush,NULL,0},{{12,3}, TripleGreenBush,NULL,0},{{17,3}, SmallGreenBush,NULL,0}, 
			{{22,3},SimpleGreenBush},{{40,3},DoubleGreenBush,NULL,0}, {{47, 3}, BigGreenBush,NULL,0}, 
			{{58, 3}, TripleGreenBush,NULL,0},{{63,3},SmallGreenBush,NULL,0},{{70,3},SimpleGreenBush}, 
			{{88, 3},DoubleGreenBush,NULL,0},{{95,3}, BigGreenBush,NULL,0},{{106,3}, TripleGreenBush,NULL,0}, 
			{{111,3},SmallGreenBush,NULL,0},{{118,3},SimpleGreenBush},{{137,3},DoubleGreenBush,NULL,0},
			{{144,3},BigGreenBush},{{160,3},SmallGreenBush,NULL,0},{{167,3},SimpleGreenBush},{{195,3},BigGreenBush,NULL,0},
			{{17,6},InterrogationPoint,NULL,0},{{21,6},Brick,NULL,0}, {{22,6},InterrogationPoint,NULL,0},{{23,6},Brick,NULL,0},
			{{24,6},InterrogationPoint,NULL,0}, {{25,6},Brick,NULL,0},{{23,10},InterrogationPoint,NULL,0},{{76,6},Brick,NULL,0}, 
			{{77,6},InterrogationPoint,NULL,0},{{78,6},Brick,NULL,0},{{79,10},Brick,NULL,0},{{80,10},Brick,NULL,0},{{81,10},Brick,NULL,0},
			{{82,10},Brick,NULL,0},{{83,10},Brick,NULL,0},{{84,10},Brick,NULL,0},{{85,10},Brick,NULL,0},{{86,10},Brick,NULL,0},{{90,10},Brick,NULL,0},
			{{91,10},Brick,NULL,0},{{92,10},Brick,NULL,0},{{93,10},InterrogationPoint,NULL,0},{{93,6},Brick,NULL,0},{{99,6},Brick,NULL,0},
			{{100,6},Brick,NULL,0},{{105,6},InterrogationPoint,NULL,0},{{108,6},InterrogationPoint,NULL,0},{{111,6},InterrogationPoint,NULL,0},{{105,10},InterrogationPoint,NULL,0}, 
			{{117,6},Brick,NULL,0},{{120,10},Brick,NULL,4}, {{128,10},Brick,NULL,0},{{129,10},InterrogationPoint,NULL,0},{{130,10},InterrogationPoint,NULL,0},{{131,10},Brick,NULL,0},
			{{129,6},Brick,NULL,0},{{130,6},Brick,NULL,0},{{169,6},Brick,NULL,0},{{170,6},Brick,NULL,0},{{171,6},Brick,NULL,0},{{172,6},Brick,NULL,0},{{133,3},Stairs,"up",4},{{139,3},Stairs, "down",4}, 
			{{147,3},Stairs,"up",5}, {{154,3},Stairs,"down",5},{{180,3},Stairs, "up",9},{{68,0}, Hole},{{85,0},BigHole}, {{152,0},Hole}, {{27,3},SmallPipe,NULL,0},{{37,3}, MiddlePipe,NULL,0},
			{{45,3},BigPipe,NULL,0},{{56,3},BigPipeEntry,NULL,0}, {{162, 3}, SmallPipeExit,NULL,0},{{178,3},SmallPipe,NULL,0},{{197,3}, Flag, NULL,0}, {{200,3},Castle,NULL,0}}};

MapGame MapInit(int lv){

	MapGame map;
	int w, h;
	printf("1");
	map.level = lv;
	printf("1");
	switch (lv){

		case 1:
			w = 250;
			h = 20;
			break;
	}
	printf("1");
	map.height = h;
	map.width = w;
	printf("1");
	map.body = (char**)calloc(h,sizeof(char*));
	for (int i=0; i<h; i++){
		map.body[i] = (char*)calloc(w,sizeof(char));
	}

	return map;
}

void PutElemInMap(Map map, Elem element, int width, int height){
	for(int i=element->c.x; i<=width+element->c.x;i++){
		for(int j=element->c.y;j<=height+element->c.y;j++ ){
			map->body[j][i]=element->type; 
		}
	} 
}

void PlaceElem(Map map){

	int lenght = sizeof(NIVEAU[map->level -1])/sizeof(Element);
	printf("%d\n", lenght);

	for(int i=0; i<lenght; i++){

		Element element = NIVEAU[map->level -1][i];

		switch(element.type){

			case Stairs :
				int k = element.size -1;
				for(int i=element.c.x; i<=element.size+element.c.x;i++){
					for(int j=3;j<=element.size+3;j++ ){
						if (k<element.size){
							map->body[j][i]=element.type;
							k++;
						}
						
					}
					k-2;
				} 
				break;

			case BigGreenBush:
				PutElemInMap(map, &element, 5, 2);
				break;

			case SmallGreenBush:
				PutElemInMap(map, &element, 3, 1);
				break;

			case SimpleGreenBush:
				PutElemInMap(map, &element, 3, 1);
				break;

			case DoubleGreenBush:
				PutElemInMap(map, &element, 4, 1);
				break;
			case TripleGreenBush:
				PutElemInMap(map, &element, 5, 1);
				break;
			case Hole:
				PutElemInMap(map, &element, 2, 2);
				break;
			case BigHole:
				PutElemInMap(map, &element, 3, 2);
				break;
			case SmallPipe:
				PutElemInMap(map, &element, 2, 2);
				break;
			case SmallPipeExit:
				PutElemInMap(map, &element, 2, 2);
				break;
			case BigPipe:
				PutElemInMap(map, &element, 2, 4);
				break;
			case BigPipeEntry:
				PutElemInMap(map, &element, 2, 4);
				break;
			case MiddlePipe:
				PutElemInMap(map, &element, 2, 3);
				break;
			case InterrogationPoint:
				PutElemInMap(map, &element, 1, 1);
				break;
			case Brick:
				PutElemInMap(map, &element, 1, 1);
				break;
			case Castle:
				PutElemInMap(map, &element, 5, 6);
				break;
			case Flag:
				PutElemInMap(map, &element, 1, 10);
				break;
		}
	}
	printf("er");
}

void PrintMap(MapGame map){
	for(int i=0; i<=map.height;i++){
		for(int j=0; j<=map.width;j++){
			printf("[%c]", map.body[i][j]);
		}
		printf("\n");
    }
}
