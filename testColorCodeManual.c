#include <assert.h>
#include <string.h>
#include "colorCodeManual.h"

extern ColorPair* colorPairPtr;

void testPrintColorMap(int expectedPairNumber,
		char expectedMajorColor[], char expectedMinorColor[]) {
	int ColorPairIndex = expectedPairNumber-1; // ColorPairIndex starts with zero
	assert(colorPairPtr[ColorPairIndex].PairNumber == expectedPairNumber);
	assert(strcmp(colorPairPtr[ColorPairIndex].MajorColor, expectedMajorColor) == 0);
	assert(strcmp(colorPairPtr[ColorPairIndex].MinorColor, expectedMinorColor) == 0);
}

int main() {
	printColorMap(&printColorMaponConsole);
	char MajorColor[] = "Yellow";
	char MinorColor[] = "Brown";
	testPrintColorMap(19, MajorColor, MinorColor);
	return 0;
}
