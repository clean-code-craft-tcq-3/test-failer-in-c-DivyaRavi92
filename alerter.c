#include "alerter.h"
#include <stdio.h>
#include <assert.h>


extern int alertFailureCount;

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    alertInCelcius(100.0);
    assert(alertFailureCount != 0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
