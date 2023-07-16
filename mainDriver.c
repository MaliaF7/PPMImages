/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Menu Project
*/
#include "defs.h"

int showMenu(){
	int menuNum =0;
	//making sure user inputs correctly, prints the menu
	printf("Image Manipulation Program\n");
	printf("1. reduce size of image #1\n");
	printf("2. superimpose image #2 onto image #1\n");
	printf("3. reduce size of superimposed image\n");
	printf("4. quit the program\n");
	scanf("%d", &menuNum);
	return menuNum;
}

void readImage(FILE* file, pixels *pixelArray, int width, int height) {

	for (int i = 0; i < width * height; i++) {
		fscanf(file, "%ud", &pixelArray[i].r);
		fscanf(file, "%ud", &pixelArray[i].g);
		fscanf(file, "%ud", &pixelArray[i].b);
	}
}

int main (int argc, char *argv[]) {
//scaning file, argv/argc stuff	
	FILE *inFile;
	FILE *inFile2;

	inFile = fopen(argv[1], "r");
	inFile2 = fopen(argv[2], "r");

//setting up the header

	header h1;
	h1 = getHeader(inFile);
	getHeader(inFile2);
	
//setting up the width
	const int arraySize = (h1.structWidth * h1.structHeight);

//declare arrays to hold input images
	pixels *arrayPtr = calloc(arraySize, sizeof(pixels));
	pixels *arrayPtr2 = calloc(arraySize, sizeof(pixels));

// read image from file
	readImage(inFile, arrayPtr, h1.structWidth, h1.structHeight);
	readImage(inFile2, arrayPtr2, h1.structWidth, h1.structHeight);
	
	int menuNum=0;

	int choice1Ctr =0;
	int choice2Ctr =0;
//Switch statement depending on what the user inputs
	while (1){
		menuNum = showMenu();
		switch (menuNum){
			case 1:
			// Reduce the size of image one
				if (choice1Ctr == 0){
					//creating space
					pixels *smallerImg = (pixels *)malloc(arraySize * sizeof(pixels));
					reduceSize(smallerImg, arrayPtr, h1.structWidth, h1.structHeight);
					
					//open up the image
					FILE *outfile;
					outfile = fopen("smallerImage1.pnm", "w");
					if (outfile == NULL) {
						printf("Output file failed to open!\n");
						exit(1);
					}
					
					//random variables
					header h2;
					h2 = h1;
					h2.structWidth = h1.structWidth / 2;
					h2.structHeight = h1.structHeight / 2;

					//calling functions and increasing choice counter
					writeHeader (outfile, h2);
					writePixels(outfile, smallerImg, h2.structWidth, h2.structHeight);
					choice1Ctr++;
					break;
				}
				else {
					//in the case that we have already chosen option 1
					printf("Menu 1 option already chosen.\n");
					showMenu();

				}
				
			case 2:
			// superimposing image 
				if (choice2Ctr ==0){
					//creating space
					pixels *greenImg = malloc(arraySize * sizeof(pixels));

					//open file, call the functions, increase counter 2
					greenScreen(arrayPtr, arrayPtr2, greenImg, h1.structWidth, h1.structHeight);//send both original and new image
					FILE *outfile = NULL;
					outfile = fopen("greenScreen1.pnm", "w");
					writeHeader(outfile, h1);
					writePixels(outfile, greenImg, h1.structWidth, h1.structHeight);
					choice2Ctr++;
					break;
				}
				else{
					//in the case that 
					printf("Menu 2 option already chosen.\n");
					showMenu();
				}
				
			case 3:
				exit(0);
				break;
				
			case 4:
				exit(0);
				break;
				
			default:
				printf("Please enter a valid number.\n");
				showMenu();
		}
	}
}
