#include "tshirtSizeInterpretation.h"
#include <assert.h>

void testTshirtSizeBasedOnShoulderLength(int size_cms, char expectedSize) {
	assert(tshirtSizeBasedOnShoulderLength(size_cms) == expectedSize);
}

int main() {
	testTshirtSizeBasedOnShoulderLength(30,'\0');
	testTshirtSizeBasedOnShoulderLength(37,'S');
	testTshirtSizeBasedOnShoulderLength(38,'S');
	testTshirtSizeBasedOnShoulderLength(40,'M');
	testTshirtSizeBasedOnShoulderLength(42,'L');
	testTshirtSizeBasedOnShoulderLength(49,'\0');
	return 0;
}
