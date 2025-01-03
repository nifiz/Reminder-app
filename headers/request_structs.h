#ifndef REQUEST_STRUCTS_H
#define REQUEST_STRUCTS_H

#include <stdint.h>

#include "enums.h"
#include "structs.h"

typedef struct {
    /* Flag tells us how to treat the data. */
    Flag flag;
    /* Data received is valid and non empty. */
    void* data;
} Parameter;

typedef struct {
    Command command;
    Parameter** paramList;
    uint8_t paramCount;
} Request;

#endif