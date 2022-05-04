#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    
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

void alertInCelcius(float farenheit) {
    float celcius = tempConversion(farenheit);
    int returnCode = networkAlertStub(celcius);
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
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(100.0);
    assert(alertFailureCount != 0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
