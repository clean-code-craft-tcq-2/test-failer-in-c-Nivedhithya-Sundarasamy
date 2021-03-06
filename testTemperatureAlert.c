#include <stdio.h>
#include <assert.h>
#include "temperatureAlert.h"

int networkAlertStub(float celcius) {
	printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius <= TEMP_THRESHOLD_CELCIUS) {
		return 200;
	} else {
		return 500;
	}
}

void testAlertInCelcius(float farenheit, int expectedAlertFailureCount){
	alertInCelcius(farenheit, networkAlertStub);
	assert(alertFailureCount == expectedAlertFailureCount);
}

void testFarenheitToCelciusConvertor(float farenheit, float expectedCelcius){
	assert(farenheitToCelciusConvertor(farenheit) == expectedCelcius);
}

int main() {
	testFarenheitToCelciusConvertor(400.5, 204.722222f);
	testFarenheitToCelciusConvertor(303.6, 150.888888f);
	testAlertInCelcius(400.5,1);
	testAlertInCelcius(303.6,1);
	testAlertInCelcius(600,2);
	return 0;
}
