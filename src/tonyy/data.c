#include <stdio.h>
#include <stdlib.h>
#include "data.h"

Map Foreground;


void CreateMap(Map *map, int level){

	switch(level){
		case 1 :
			//height :400 pixels
			// block = 25 pixels
			/*
			buisson1: 5 block

			*/
			Element* bush= {{0,3}, BigGreenBush,'',0},{{12,3}, TripleGreenBush,'',0},{{17,3}, SmallGreenBush,'',0}, {{22,3},SimpleGreenBush},{{40,3},DoubleGreenBush,'',0}, {{47, 3}, BigGreenBush,'',0}, {{58, 3}, TripleGreenBush,'',0},{{63,3},SmallGreenBush,'',0},{{70,3},SimpleGreenBush}, {{88, 3},DoubleGreenBush,'',0},{{95,3}, BigGreenBush,'',0},{{106,3}, TripleGreenBush,'',0}, {{111,3},SmallGreenBush,'',0},{{118,3},SimpleGreenBush},{{137,3},DoubleGreenBush,'',0},{{144,3},BigBreenBush},{{160,3},SmallGreenBush,'',0},{{167,3},SimpleGreenBush},{{195,3},BigGreenBush,'',0},
		{{17,6},InterrogationPoint,'',0},{{21,6},Brick,'',0}, {{22,6},InterrogationPoint,'',0},{{23,6},Brick,'',0},{{24,6},InterrogationPoint,'',0}, {{25,6},Brick,'',0},{{23,10},InterrogationPoint,'',0},{{76,6},Brick,'',0}, {{77,6},InterrogationPoint,'',0},{{78,6},Brick,'',0},{{79,10},Brick,'',0},{{80,10},Brick,'',0},{{81,10},Brick,'',0},{{82,10},Brick,'',0},{{83,10},Brick,'',0},{{84,10},Brick,'',0},{{85,10},Brick,'',0},{{86,10},Brick,'',0},{{90,10},Brick,'',0},{{91,10},Brick,'',0},{{92,10},Brick,'',0},{{93,10},InterrogationPoint,'',0},{{93,6},Brick,'',0},{{99,6},Brick,'',0},{{100,6},Brick,'',0},{{105,6},InterrogationPoint,'',0},{{108,6},InterrogationPoint,'',0},{{111,6},InterrogationPoint,'',0},};

			CreateGround();
			CreateStares();

	}


}
