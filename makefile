# Malia Fairbanks | mfairba
# November 13, 2022
# Section 5, PA4
# Makefile for pointers


PA4: defs.h mainDriver.c getHeader.c writeHeader.c writePixels.c
	gcc -Wall -o PA4 mainDriver.c initInputImageArray.c getHeader.c writeHeader.c writePixels.c manip.c

run: PA4
	./PA4 Disney.pnm ClemsonPaw.pnm

clean:
	rm PA4
