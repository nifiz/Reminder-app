#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "enums.h"
#include "parser.h"
#include "request_structs.h"
#include "parameter_loaders.h"

Command validateCommand(const char* command) 
{
    for (int i = 0; i < COMMAND_AMOUNT; i++) 
    {
        if (strcmp(command, COMMAND_STRING_TABLE[i])) return (Command)i;
    }
    return error;
}

RawParameterCollection structifyParams(int argc, char** argv) 
{
    /* Warning: allocates memory on heap. */

    RawParameterCollection rpc = {NULL, 0};

    /* In case flag has no parameter. */
    if (argc % 2 == 1) return rpc;

    uint8_t structAmount =  (argc - 2)/2;

    RawParameter* localParamArray = malloc(sizeof(RawParameter) * structAmount);

    /* Args 0 and 1 are name and command. */
    for (int i = 2; i < argc; i+=2)
    {
        localParamArray[(i/2) - 1].flag = validateFlag(argv[i]);
        localParamArray[(i/2) - 1].param = argv[i+1];
        localParamArray[(i/2) - 1].paramLen = strlen(argv[i+1]);
    }

    rpc.rawParameterArray = localParamArray;
    rpc.size = structAmount;

    return rpc;
}

static Flag validateFlag(const char* flag) 
{
    /* Check if flag is a valid string*/

    for (int i = 0; i < FLAG_AMOUNT; i++) 
    {
        if (strcmp(flag, FLAG_STRING_TABLE[i])) return (Flag)i;
    }
    return badFlag;
}

static bool loadParameter(Flag f, const char* parameter, Parameter* dest)
{
    /* Check if given parameter is valid for provided flag. */
    bool success = false;
    switch (f)
    {
    case msg:
        success = FlagMessageLoadParam(parameter, dest);
        break;
    case color:
        success = FlagColorLoadParam  (parameter, dest);
        break;
    case when:
        success = FlagWhenLoadParam   (parameter, dest);
    case freq:
        success = FlagFreqLoadParam   (parameter, dest);
        break;
    case id:
        success = FlagIdLoadParam     (parameter, dest);
        break;
    default:
        break;
    }

    return success;
    
}

Request createRequest(const RawParameterCollection* rpc) 
{
    for (uint8_t i = 0; i < rpc->size; i++) 
    {
        loadParameter()
    }
}



