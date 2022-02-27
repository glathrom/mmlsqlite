#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "parse.h"



int main(int argc, char **argv){

    FILE *fp;
    int numNewLines;

    if( argc < 2 ){
        fprintf(stderr, "Usage: parse <filename>\n");
        exit(0);
    } else if( (fp = fopen(argv[1], "r")) == NULL ){
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }


    numNewLines = findNewLines(fp);  
    printf("Number of newlines found = %d\n", numNewLines);

    fclose(fp);

    return 0;
}
