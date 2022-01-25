#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
	assert(size(37) == 'S');
	assert(size(38) == 'S'); //Size 38 isn't included in neither 'S' nor 'M' 
	assert(size(40) == 'M');
	assert(size(42) == 'M'); //Size 42 isn't included in neither 'M' nor 'L'
	assert(size(43) == 'L');
	assert(size(30) != 'S'); //Small size lower limit is not specified
	assert(size(50) != 'L'); //Large size higher limit is not specified
	printf("All is well (maybe!)\n");
	return 0;
}
