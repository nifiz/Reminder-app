#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "enums.h"
#include "parser.h"

Command validateCommand(const char* command) 
{
    for (int i = 0; i < COMMAND_AMOUNT; i++) 
    {
        if (strcmp(command, COMMAND_STRING_TABLE[i])) return (Command)i;
    }
    return error;
}

RawParameterCollection structifyParams(int argc, char** argv, RawParameter* RawParameterArray) 
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

static bool loadParameter(Flag f, const char* parameter)
{
    /* Check if given parameter is valid for provided flag. */
    bool success = false;
    switch (f)
    {
    case msg:
        success = FlagMessageLoadParam(parameter);
        break;
    case color:
        success = FlagColorLoadParam  (parameter);
        break;
    case when:
        success = FlagWhenLoadParam   (parameter);
    case freq:
        success = FlagFreqLoadParam   (parameter);
        break;
    case id:
        success = FlagIdLoadParam     (parameter);
        break;
    default:
        break;
    }

    return success;
    
}



