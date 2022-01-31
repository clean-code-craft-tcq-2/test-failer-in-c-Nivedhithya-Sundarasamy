#define TEMP_THRESHOLD_CELCIUS 175

extern int alertFailureCount;
void networkAlertFailureCheck(int returnCode); 
extern float farenheitToCelciusConvertor (float farenheit);
extern void alertInCelcius(float farenheit, int (*fpNetworkAlert) (float));
