#include "parse.h"


uint64_t findMaxLineSize(FILEINFO_t *F){
    int count = 0;
    int size;
    char *buf;
    uint64_t currentPos, prevPos;
    uint64_t maxbufsize = 0;

    buf = malloc(strlen(NEWLINE)*sizeof(char));

    rewind(F->fp);
    prevPos = ftell(F->fp);
    while( (size = fread(buf, sizeof(char), strlen(NEWLINE), F->fp)) == strlen(NEWLINE) ){
        if( strcmp(buf, NEWLINE) == 0 ){
            count++;
            currentPos = ftell(F->fp);
            if( currentPos - prevPos > maxbufsize )
                maxbufsize = currentPos - prevPos;
            prevPos = currentPos;                
        }
        fseek(F->fp,1-strlen(NEWLINE),SEEK_CUR);
    }

    free(buf);
    rewind(F->fp);

    return maxbufsize;
}

void readLine(char *line, FILEINFO_t *F){
    char *buf;
    uint64_t prevPos, currentPos;
    int size;

    buf = malloc(strlen(NEWLINE)*sizeof(char));

    prevPos = ftell(F->fp);
    fread(buf, sizeof(char), strlen(NEWLINE), F->fp);
    while( strcmp(buf, NEWLINE) != 0 ){
        fseek(F->fp,1-strlen(NEWLINE),SEEK_CUR);
        fread(buf, sizeof(char), strlen(NEWLINE), F->fp);
    }
    currentPos = ftell(F->fp);
    size = currentPos - prevPos;
    fseek(F->fp,-size,SEEK_CUR);
    fread(line,sizeof(char),size,F->fp);

    free(buf);
}

void parseTitles(FILEINFO_t *F){
    char *buf;
    char *token;
    
    rewind(F->fp);
    buf = malloc((F->maxlinesize)*sizeof(char));
    readLine(buf,F);

    token = strtok(buf,DELIMITER);
    printf("%s\n", token);
    while((token = strtok(NULL,DELIMITER)) != NULL)
        printf("%s\n", token);

    free(buf);
}

