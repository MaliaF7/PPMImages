/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Image Project
*/
#include "defs.h"
void writePixels(FILE *fileeee, pixels pixelArray[],int structWidth,int structHeight) {

	for (int i = 0; i < structWidth * structHeight; i++) {
		fprintf(fileeee, "%d %d %d\n", pixelArray[i].r, pixelArray[i].g, pixelArray[i].b);
	}

}
