#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#ifndef DELIMITER
#define DELIMITER ","
#endif

#ifndef NEWLINE
#define NEWLINE "\r\n"
#endif

typedef struct FILEINFO {
    FILE *fp;
    uint64_t maxlinesize;
} FILEINFO_t;

uint64_t findMaxLineSize(FILEINFO_t *);
void readLine(char *, FILEINFO_t *);
void parseTitles(FILEINFO_t *);

#endif
