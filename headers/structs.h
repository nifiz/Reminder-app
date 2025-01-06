#ifndef STRUCTS_H
#define STRUCTS_H

#include <time.h>
#include <stdint.h>

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

RawParameter RPCGetElementAt(const RawParameterCollection* rpc, uint8_t position);

typedef struct
{
    struct tm startDate;
    struct tm frequency;

} Timing;

Timing loadTiming(const char* date, const char* freq);

typedef struct
{
    char* message;
    unsigned long long messageLen;
    unsigned long long int id;
    char* color;
    Timing timing;

} Idea;

#endif