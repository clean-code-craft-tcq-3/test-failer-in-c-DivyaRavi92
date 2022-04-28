/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
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
