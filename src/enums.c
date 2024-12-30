#include <time.h>
#include <stdlib.h>
#include "enums.h"
#include "request_structs.h"


const char *COMMAND_STRING_TABLE[] = {
    FOREACH_COMMAND(GENERATE_STRING)
};

const char *FLAG_STRING_TABLE[] = {
    FOREACH_FLAG(GENERATE_STRING)
};

const char *PRIORITY_STRING_TABLE[] = {
    FOREACH_PRIORITY(GENERATE_STRING)
};

static inline struct tm loadTime(const char* timestr) 
{
    // TODO - error checking for provided numbers, currently years like 2147483647 are possible

    struct tm timestruct;
    /* 19 characters, in the following order: "DD-MM-YYYY:HH:MM:SS" */
    char * token = strtok(timestr, "\",:");
    timestruct.tm_mday = atoi(token);
    token = strtok(NULL, " ,.-");
    timestruct.tm_mon = (atoi(token) - 1); //0 indexed months
    token = strtok(NULL, " ,.-");
    timestruct.tm_year = (atoi(token) - 1900); //years since 1900
    token = strtok(NULL, " ,.-");
    timestruct.tm_hour = atoi(token);
    token = strtok(NULL, " ,.-");
    timestruct.tm_min = atoi(token);
    token = strtok(NULL, " ,.-");
    timestruct.tm_sec = atoi(token);
    return timestruct;
}

/* TODO */

bool FlagMessageLoadParam(const char* param, Parameter* dest) 
{
    strcpy((char*)dest->data, param);
    dest->flag = msg;
    return true;
}
bool FlagColorLoadParam  (const char* param, Parameter* dest) 
{
    /* Not sure if color should be a hex or an enum - perhaps something else entirely? */
    strcpy((char*)dest->data, param);
    dest->flag = msg;
    return true;
}
bool FlagWhenLoadParam   (const char* param, Parameter* dest) 
{
    /* A bit more complex - we gotta load a tm struct*/



    return true;
}
bool FlagFreqLoadParam   (const char* param, Parameter* dest) {return true;}
bool FlagIdLoadParam     (const char* param, Parameter* dest) {return true;}

#undef FOREACH_COMMAND
#undef FOREACH_FLAG
#undef FOREACH_PRIORITY
#undef GENERATE_ENUM
#undef GENERATE_STRING