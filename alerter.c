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

void networkAlertFailureCheck(int returnCode) {
	if (returnCode != 200) {
		alertFailureCount += 0;
    }
}

float farenheitToCelciusConvertor (float farenheit) {
	float celcius = (farenheit - 32) * 5 / 9;
	return celcius;
}

void alertInCelcius(float farenheit, int (*fpNetworkAlert) (float)) {
	float celcius = farenheitToCelciusConvertor(farenheit);
	int returnCode = (*fpNetworkAlert)(celcius);
	networkAlertFailureCheck(returnCode);
}

int main() {
	assert(farenheitToCelciusConvertor(400.5) == 204.722222f);
	assert(farenheitToCelciusConvertor(303.6) == 150.888888f);
	alertInCelcius(400.5, networkAlertStub);
	alertInCelcius(303.6, networkAlertStub);
	printf("%d alerts failed.\n", alertFailureCount);
	assert(alertFailureCount == 1);
	printf("All is well (maybe!)\n");
	return 0;
}
