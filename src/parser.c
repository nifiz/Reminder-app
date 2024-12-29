#include "parser.h"
#include <string.h>
#include "enums.h"

Command validateCommand(char* command) 
{
    for (int i = 0; i < COMMAND_AMOUNT; i++) 
    {
        if (strcmp(command, COMMAND_STRING_TABLE[i])) return (Command)i;
    }

    return error;
}