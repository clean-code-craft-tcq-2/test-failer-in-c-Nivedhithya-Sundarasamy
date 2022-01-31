#include <stdio.h>
#include "tshirtSizeInterpretation.h"

char tshirtSizeBasedOnShoulderLength(int size_cms) {
    char sizeName = '\0';
    if(size_cms > SMALL_SIZE_LOWER_LIMIT &&
			size_cms <= SMALL_SIZE_UPPER_LIMIT) {
        sizeName = 'S';
    } else if(size_cms > MEDIUM_SIZE_LOWER_LIMIT &&
			size_cms < MEDIUM_SIZE_UPPER_LIMIT) {
        sizeName = 'M';
    } else if(size_cms >= LARGE_SIZE_LOWER_LIMIT &&
			size_cms < LARGE_SIZE_UPPER_LIMIT) {
        sizeName = 'L';
    } else {
	}
    return sizeName;
}

