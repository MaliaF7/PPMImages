/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Image Project
*/
 #include "defs.h"

void  writeHeader(FILE *outFile, header h2) {
	fprintf(outFile,"%s\n", h2.type);
   fprintf(outFile, "%d %d %d\n", h2.structWidth, h2.structHeight, 255);
}

