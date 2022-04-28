#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int printColorMap() {
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int printColorPair(int majorColorNumber, int minorColorNumber) 
{
    int i = majorColorNumber, j = minorColorNumber, pairNumber;
    printf("ColorPair\n");
    printf("%d | %s | %s\n", i * 5 + j, majorColor[majorColorNumber], minorColor[minorColorNumber]);
    pairNumber = i * 5 + j;   
    return pairNumber;
}

int main() {
    int majorColorNumber = 1;
    int minorColorNumber = 2;
    int result = printColorMap();
    int pairNumber = printColorPair(majorColorNumber, minorColorNumber);
    assert(result == 25);
    assert(pairNumber == 8);
    printf("All is well (maybe!)\n");
    return 0;
}
