#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
	printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius <= 175) {
		return 200;
	} else {
		return 500;
	}
}

void networkAlertCheck(int returnCode) {
	if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
		alertFailureCount += 0;
    }
}

int alertInCelcius(float farenheit) {
	float celcius = (farenheit - 32) * 5 / 9;
	int returnCode = networkAlertStub(celcius);
	return returnCode;
}

int main() {
	int returnCode;
	returnCode = alertInCelcius(400.5);
	networkAlertCheck(returnCode);
	returnCode = alertInCelcius(303.6);
	networkAlertCheck(returnCode);
	printf("%d alerts failed.\n", alertFailureCount);
	assert(alertFailureCount == 1);
	printf("All is well (maybe!)\n");
	return 0;
}
