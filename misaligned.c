#include <stdio.h>
#include <assert.h>
#include "misaligned.h"
#include "test_colorMap.h"

int printColorMap(void)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    char string[30];
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
       	{
	    buildColorMapString(i,j,string);
            printStringToConsole(string);
        }
    }
    return i * j;
}

// This function will build string for color map for providedd index.
// param[in]: i = index of majorColor
// param[in]:j = index of minorColor
// param[in]: string = to hold the content of the colormap in string format.
// param[out]: pointer to string of colorCode.
void  buildColorMapString(int i, int j, char* string)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    sprintf(string,"%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
}

void printStringToConsole(char* string)
{
    printf("%s",string);
}

int main()
{
    int result = printColorMap();
    assert(result == 25);
    test_printColorMap();
    printf("All is well (maybe!)\n");
    return 0;
}
