#include "parse.h"


int findNewLines(FILE *fp){
    int count = 0;
    int size;
    char *buf;

    buf = malloc(strlen(NEWLINE)*sizeof(char));

    rewind(fp);
    while( (size = fread(buf, sizeof(char), strlen(NEWLINE), fp)) == strlen(NEWLINE) ){
        if( strcmp(buf, NEWLINE) == 0 ){
            count++;
        }
        fseek(fp,1-strlen(NEWLINE),SEEK_CUR);
    }

    free(buf);

    return count;
}
