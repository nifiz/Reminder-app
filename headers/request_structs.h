#ifndef REQUEST_STRUCTS_H
#define REQUEST_STRUCTS_H
#include "enums.h"
#include <stdint.h>

typedef struct {
    Command command;
    Parameter** paramList;
    uint8_t paramCount;
} Request;

typedef struct {
    /* Flag tells us how to treat the data. */
    Flag flag;
    /* Data received is valid and non empty. */
    void* data;
} Parameter;

#endif