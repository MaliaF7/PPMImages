/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Image Project
*/
#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int structWidth, structHeight, maxColor;
   	char type[4];
}header;

typedef struct {
	unsigned int r,g,b;
}pixels;

header getHeader (FILE *inFile);
void writeHeader (FILE *outFile, header h2);
void fillImageArray (FILE *outFile, pixels theArray[], int width, int height);
void writePixels(FILE *outFile, pixels myArray2[], int structWidth, int structHeight);
void greenScreen(pixels myArray1[], pixels myArray2[], pixels myArray3[], int structWidth, int structHeight);
void reduceSize(pixels myArray1[], pixels myArray2[], int width, int height);
int showMenu();
#endif
