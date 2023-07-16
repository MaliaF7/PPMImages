/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4 
   Final Image Project
*/
#include "defs.h"

void fillImageArray (FILE *inFile, pixels theArray[],int structWidth, int structHeight){
	int i;
	for (i=0;i<(structWidth*structHeight);i++){
		fscanf(inFile, "%i", &theArray[i].r);
		fscanf(inFile, "%i", &theArray[i].g);
		fscanf(inFile, "%i", &theArray[i].b);
	}

}

