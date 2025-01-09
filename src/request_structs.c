#include <stdlib.h>

#include "../headers/request_structs.h"
#include "../headers/parser.h"
#include "../headers/parameter_loaders.h"

Request createRequest(const RawParameterCollection* source, Command command) 
{
    Request r = {command, NULL, source->size};

    r.paramList = malloc(sizeof(Parameter *) * source->size);

    for (uint8_t i = 0; i < source->size; i++) 
    {
        RawParameter rp = RPCGetElementAt(source, i);
        r.paramList[i] = malloc(sizeof(Parameter));

        loadParameter(&rp, r.paramList[i]);
    }

    return r;
}