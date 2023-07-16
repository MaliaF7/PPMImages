/* Malia Fairbanks | mfairba
   CpSc Lab Section 5, December 7, 2022
   PA4
   Final Image Project
*/
#include "defs.h"

//creates an array that stores the reduced pixels
void reduceSize (pixels myArray1[], pixels myArray2[], int structWidth, int structHeight) {

	 int avgr, avgg, avgb;

	for (int row = 0; row < structHeight / 2; row++) {
		for (int col = 0; col < structWidth / 2; col++) {
			avgr = (myArray2[(row * 2 * structWidth) + (col * 2)].r
				+ myArray2[(row * 2 * structWidth) + (col * 2)+1].r
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth].r
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth +1].r)/4;
			myArray1[(row * structWidth / 2) + col].r = avgr;
			avgg = (myArray2[(row * 2 * structWidth) + (col * 2)].g
				+ myArray2[(row * 2 * structWidth) + (col * 2)+1].g
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth].g
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth +1].g)/4;
			myArray1[(row * structWidth / 2) + col].g = avgg;
			avgb = (myArray2[(row * 2 * structWidth) + (col * 2)].b
				+ myArray2[(row * 2 * structWidth) + (col * 2)+1].b
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth].b
				+ myArray2[(row * 2 * structWidth) + (col * 2)+structWidth +1].b)/4;
			myArray1[(row * structWidth / 2) + col].b = avgb;
		}
	}
}

//the green screen function
void greenScreen (pixels myArray1[], pixels myArray2[], pixels myArray3[], int structWidth, int structHeight){
	for (int i=0; i<(structWidth *structHeight); i++){
		if (myArray2[i].r == 0 && myArray2[i].g == 255 && myArray2[i].b == 0) {
			
			myArray3[i].r = myArray1[i].r;
			myArray3[i].g = myArray1[i].g;
			myArray3[i].b = myArray1[i].b;
		}
		else {
			myArray3[i].r = myArray2[i].r;
			myArray3[i].g = myArray2[i].g;
			myArray3[i].b = myArray2[i].b;
			
		}
	}


}


