#include <stdio.h>

#include <assert.h>
#include <string.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

typedef struct {
	int PairNumber;
	char MajorColor[10];
	char MinorColor[10];
} ColorPair;

void printColorMaponConsole(int d, const char *s1, const char *s2 ) {
	printf("%d | %s | %s\n", d, s1, s2);
}

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printColorMaponConsole(i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

ColorPair fakeprintColorMaponConsole(int d, const char *s1, const char *s2){
	ColorPair colorpair;
	colorpair.PairNumber = d;
	strcpy(colorpair.MajorColor, s1);
	strcpy(colorpair.MinorColor, s2);
	return colorpair;
}

int main() {
   	int result = printColorMap();
	int i=4, j=3;
	assert(result == 25);
	ColorPair colorpair;
	colorpair = fakeprintColorMaponConsole(i * 5 + j,  majorColor[i], minorColor[i]);
	//Assertions added on values given for print for provided 'i' and 'j'
	assert(colorpair.PairNumber == 23);	
	assert(strcmp(colorpair.MajorColor, "Violet") == 0);
	assert(strcmp(colorpair.MinorColor, "Green") == 0);
	printf("All is well (maybe!)\n");
	return 0;
}

