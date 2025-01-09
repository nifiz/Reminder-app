#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "../headers/enums.h" 
#include "../headers/parser.h"
#include "../headers/request_structs.h"
#include "../headers/parameter_loaders.h"

#define DEBUG

Command validateCommand(const char* command) 
{
    for (int i = 0; i < COMMAND_AMOUNT; i++) 
    {
        if (!strcmp(command, COMMAND_STRING_TABLE[i])) return (Command)i;
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

    rpc.rawParameterArray = malloc(sizeof(RawParameter*)*structAmount);

    /* Initialize first pointers */
    for (uint8_t i = 0; i < structAmount; i++) 
    {
        rpc.rawParameterArray[i] = malloc(sizeof(RawParameter));
        rpc.rawParameterArray[i]->flag = validateFlag(argv[(i*2)+2]); /* we want to access 3rd element, 5th and so on*/
        rpc.rawParameterArray[i]->param = argv[(i*2)+3]; /* 4th, 6th, ...*/
        rpc.rawParameterArray[i]->paramLen = strlen(argv[(i*2)+3]);
        #ifdef DEBUG
        printf("flag: %d, str:%s\n",rpc.rawParameterArray[i]->flag, FLAG_STRING_TABLE[(int)rpc.rawParameterArray[i]->flag] );
        printf("parameter: %s\n", rpc.rawParameterArray[i]->param);
        printf("param length: %d\n", rpc.rawParameterArray[i]->paramLen);
        #endif
    }

    rpc.size = structAmount;

    return rpc;
}

static Flag validateFlag(const char* flag) 
{
    /* Check if flag is a valid string */

    for (int i = 0; i < FLAG_AMOUNT; i++) 
    {
        /* add 1 to account for a -dash before a flag */
        if (!strcmp((flag+1), FLAG_STRING_TABLE[i])) return (Flag)i;
    }
    return badFlag;
}



