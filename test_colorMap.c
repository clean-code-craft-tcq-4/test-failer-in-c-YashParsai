#include "test_colorMap.h"
#include "misaligned.h"

void test_printColorMap(void)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char string[30];
    char string_test[30];

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            sprintf(string_test,"%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
            buildColorMapString(i,j,string);
            assert(!strcmp(string,string_test));
        }
    }
}

