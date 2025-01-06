#ifndef REQUEST_STRUCTS_H
#define REQUEST_STRUCTS_H

#include <stdint.h>

#include "enums.h"
#include "structs.h"

/* Contains: Flag flag, void* data */
typedef struct {
    /* Flag tells us how to treat the data. */
    Flag flag;
    /* Data received is valid and non empty. */
    void* data;
} Parameter;

/* Contains: Command command, Parameter** paramList, uint8_t paramCount */
typedef struct {
    Command command;
    Parameter** paramList;
    uint8_t paramCount;
} Request;

Request createRequest(const RawParameterCollection* source, Command command);

#endif