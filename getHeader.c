/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Image Project
*/

#include "defs.h"

header getHeader(FILE *inFile ) {
	header header1;
	fscanf(inFile, "%s",header1.type);
	fscanf(inFile, "%i", &header1.structWidth);
	fscanf(inFile, "%i", &header1.structHeight);
	fscanf(inFile, "%i", &header1.maxColor);
	
	return header1;
}
