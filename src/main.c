#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

#include "parse.h"



int main(int argc, char **argv){

    FILEINFO_t meta;
    

    if( argc < 2 ){
        fprintf(stderr, "Usage: parse <filename>\n");
        exit(0);
    } else if( (meta.fp = fopen(argv[1], "r")) == NULL ){
        fprintf(stderr, "%s\n", strerror(errno));
        exit(1);
    }

    meta.maxlinesize = findMaxLineSize(&meta);
    parseTitles(&meta);


    fclose(meta.fp);

    return 0;
}
