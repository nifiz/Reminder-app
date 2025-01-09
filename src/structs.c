#include "../headers/structs.h"

RawParameter RPCGetElementAt(const RawParameterCollection* rpc, uint8_t position) 
{
    /* rpc - pointer to a RawParameterCollection, position - 0 indexed position of the parameter */
    RawParameter rp = {error, NULL, 0}; /* Erronous data by default */
    
    if (rpc == NULL && position >= rpc->size) return rp;

    rp = *rpc->rawParameterArray[position];

    return rp;
}

