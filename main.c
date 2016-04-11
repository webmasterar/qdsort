//License MIT 2016 Ahmad Retha

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qtsort.h>

void usage()
{
    printf("This sample program prints out the sorted char string argument.\n");
    printf("Usage: ./main QWASZXERDFCVTYGHBNUIJKMOLP\n");
}

int main(int argc, char * argv[])
{
    if (argc == 1) {
        usage();
        return 1;
    }

    char * x = NULL;
    int i = 1, totLen = 0, len = 0;

    while(i != argc)
    {
        len = strlen(argv[i]);
        x = (char *) realloc(x, totLen + len + 1);
        memcpy(&x[totLen], argv[i], len);
        totLen += len;
        i++;
    }
    x[totLen] = '\0';

    printf("%s\n", x);

    qtsort_chars(x);

    printf("%s\n", x);

    free(x);

    return 0;
}
