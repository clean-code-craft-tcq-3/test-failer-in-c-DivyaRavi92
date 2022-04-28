
#include <stdio.h>

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
