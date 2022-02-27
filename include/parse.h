#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DELIMITER
#define DELIMITER ","
#endif

#ifndef NEWLINE
#define NEWLINE "\r\n"
#endif

int findNewLines(FILE *);

#endif
