#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Element NIVEAU[3][300] =  {{{{0,2}, BigGreenBush,NULL,0},{{12,2}, TripleGreenBush,NULL,0},{{17,2}, SmallGreenBush,NULL,0}, 
			{{22,2},SimpleGreenBush},{{40,2},DoubleGreenBush,NULL,0}, {{47, 2}, BigGreenBush,NULL,0}, 
			{{58, 2}, TripleGreenBush,NULL,0},{{63,2},SmallGreenBush,NULL,0},{{70,2},SimpleGreenBush}, 
			{{88, 2},DoubleGreenBush,NULL,0},{{95,2}, BigGreenBush,NULL,0},{{106,2}, TripleGreenBush,NULL,0}, 
			{{111,2},SmallGreenBush,NULL,0},{{118,2},SimpleGreenBush},{{137,2},DoubleGreenBush,NULL,0},
			{{144,2},BigGreenBush},{{160,2},SmallGreenBush,NULL,0},{{167,2},SimpleGreenBush},{{195,2},BigGreenBush,NULL,0},
			{{17,5},InterrogationPoint,NULL,0},{{21,5},Brick,NULL,0}, {{22,5},InterrogationPoint,NULL,0},{{23,5},Brick,NULL,0},
			{{24,5},InterrogationPoint,NULL,0}, {{25,5},Brick,NULL,0},{{23,9},InterrogationPoint,NULL,0},{{76,5},Brick,NULL,0}, 
			{{77,5},InterrogationPoint,NULL,0},{{78,5},Brick,NULL,0},{{79,9},Brick,NULL,0},{{80,9},Brick,NULL,0},{{81,9},Brick,NULL,0},
			{{82,9},Brick,NULL,0},{{83,9},Brick,NULL,0},{{84,9},Brick,NULL,0},{{85,9},Brick,NULL,0},{{86,9},Brick,NULL,0},{{90,9},Brick,NULL,0},
			{{91,9},Brick,NULL,0},{{92,9},Brick,NULL,0},{{93,9},InterrogationPoint,NULL,0},{{93,5},Brick,NULL,0},{{99,5},Brick,NULL,0},
			{{100,5},Brick,NULL,0},{{105,5},InterrogationPoint,NULL,0},{{108,5},InterrogationPoint,NULL,0},{{111,5},InterrogationPoint,NULL,0},{{105,9},InterrogationPoint,NULL,0}, 
			{{117,5},Brick,NULL,0},{{120,9},Brick,NULL,4}, {{128,9},Brick,NULL,0},{{129,9},InterrogationPoint,NULL,0},{{130,9},InterrogationPoint,NULL,0},{{131,9},Brick,NULL,0},
			{{129,5},Brick,NULL,0},{{130,5},Brick,NULL,0},{{169,5},Brick,NULL,0},{{170,5},Brick,NULL,0},{{171,5},Brick,NULL,0},{{172,5},Brick,NULL,0},{{133,2},Stairs,"up",4},{{140,2},Stairs, "down",4}, 
			{{147,2},Stairs,"up",5}, {{154,2},Stairs,"down",5},{{180,2},Stairs, "up",9},{{68,0}, Hole},{{85,0},BigHole}, {{152,0},Hole}, {{27,2},SmallPipe,NULL,0},{{37,2}, MiddlePipe,NULL,0},
			{{45,2},BigPipe,NULL,0},{{56,2},BigPipeEntry,NULL,0}, {{162, 2}, SmallPipeExit,NULL,0},{{178,2},SmallPipe,NULL,0},{{197,2}, Flag, NULL,0}, {{200,2},Castle,NULL,0}}};

void MapInit(int lv, MapGame * map){ 
	int w, h; 
	map->level = lv;
	switch (lv){

		case 1:
			w = 250;
			h = 20;
			break;
	}
	 
	map->height = h;
	map->width = w;
	map->body = (char**)calloc(h,sizeof(char*));
	for (int i=0; i<h; i++){
		map->body[i] = (char*)calloc(w,sizeof(char));
	}
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
					k-1-i;
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
	
}

void PrintMap(Map map){
	printf("%d %d ", map->height, map->width); 
	for(int i=0; i<=map->height;i++){
		for(int j=0; j<=map->width;j++){
			printf("[%c]", map->body[i][j]);
			return; 
		}

		printf("\n");
    }
    return; 
}

