#include "alerter.h"

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    
        printf("Temperature is %.1f celcius.\n", celcius);
        return 200;
   
}

int networkAlertProduction(float celcius) {
    
    if(celcius < 50.0)
    {
        printf("Temperature is %.1f celcius.\n", celcius);
        return 200;
    }
    else
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
}

float tempConversion(float farenheit)
{
  float celcius;
  celcius = (farenheit - 32) * 5 / 9;
  return celcius; 
}

void alertInCelcius(float farenheit, testEnvironment environment) {
    float celcius = tempConversion(farenheit);
    int returnCode;
    if(environment == networkStub)
    {
        returnCode = networkAlertStub(celcius);
    }
    else
    {
        returnCode = networkAlertProduction(celcius);
    }    
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
        printf("alertFailureCount = %d.\n", alertFailureCount);
    }
    
}


int main() {
    alertInCelcius(400.5, networkStub);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6, networkProd);
    assert(alertFailureCount == 1);
    alertInCelcius(100.0, networkStub);
    assert(alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
