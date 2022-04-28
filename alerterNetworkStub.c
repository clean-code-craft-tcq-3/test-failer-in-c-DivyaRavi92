
#include <stdio.h>
#include "alerter.h"

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
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

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
        printf("alertFailureCount = %d.\n", alertFailureCount);
    }
    
}
