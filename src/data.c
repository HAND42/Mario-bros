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
			Coord* bush= {{0,0, BigBush},{11,0, TripleGreenBush},{15,0, SmallGreenBush}, {22,0,SimpleGreenBush},{40,0,DoubleGreenBush}, {47, 0, BigGreenBush}, {58, 0, TripleGreenBush},{63,0,SmallGreenBush},{70,0,SimpleGreenBush}, {88, 0,DoubleGreenBush},{95,0, BigGreenBush},{106,0, TripleGreenBush}, {111,0,SmallGreenBush},{118,0,SimpleGreenBush},{137,0,DoubleGreenBush},{144,0,BigBreenBush},{160,0,SmallGreenBush},{167,0,SimpleGreenBush},{195,0,BigGreenBush}}
			CreateGround();
			CreateStares();

	}


}
