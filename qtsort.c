//License MIT 2016 Ahmad Retha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "qtsort.h"

void qtsort_chars (char * x)
{
    unsigned int length = strlen(x);
    unsigned int i;
    int min = INT_MAX, max = INT_MIN;

    //determine the min/max values in the array
    for (i = 0; i < length; i++)
    {
        if (x[i] < min)
        {
            min = (int) x[i];
        }
        if (x[i] > max)
        {
            max = (int) x[i];
        }
    }

    //create dictionary array
    unsigned int range = max - min + 1;
    char * dic;
    dic = (char *) calloc(range, sizeof(char));

    //get letter frequencies of x
    for (i = 0; i < length; i++)
    {
        dic[(int)x[i] - min]++;
    }

    //loop through the dictionary in lexicographical order and insert chars back into x in sorted order
    unsigned int j;
    char c;
    for (i = 0, j = 0; j < range; j++)
    {
        c = j + min;
        while(dic[j] > 0) {
            x[i] = c;
            i++;
            dic[j]--;
        }
    }

    free(dic);
}
