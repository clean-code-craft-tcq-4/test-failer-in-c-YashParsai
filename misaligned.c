#include <stdio.h>
#include <assert.h>
#include <string.h>

void printStringToConsole(char* string)
{
    printf("%s",string);
}

// This function will build string for color map for provided index.
// param[in]: i = index of majorColor
// param[in]:j = index of minorColor
// param[in]: string = to hold the content of the colormap in string format.
// param[out]: pointer to string of colorCode.
void  buildColorMapString(int i, int j, char* string)
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    
    sprintf(string,"%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[j]);
}

int printColorMap(void)
{
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


int main()
{
    int result = printColorMap();
    assert(result == 25);
    test_printColorMap();
    printf("All is well\n");
    return 0;
}
