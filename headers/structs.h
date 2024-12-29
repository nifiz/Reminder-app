#ifndef STRUCTS_H
#define STRUCTS_H

#include <time.h>
#include "enums.h"

typedef struct 
{
    Flag flag;
    char* param;
    unsigned long long paramLen;
} RawParameter;

typedef struct
{
    struct tm startDate;
    struct tm frequency;

} Timing;

typedef struct
{
    char* message;
    unsigned long long messageLen;
    char* color;
    Timing timing;
} Idea;

#endif