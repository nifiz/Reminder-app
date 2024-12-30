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
    RawParameter* rawParameterArray;
    uint8_t size;
} RawParameterCollection;

typedef struct
{
    struct tm startDate;
    struct tm frequency;

} Timing;

Timing loadTiming(struct tm date, struct tm freq);

typedef struct
{
    char* message;
    unsigned long long messageLen;
    unsigned long long int id;
    char* color;
    Timing timing;

} Idea;

#endif