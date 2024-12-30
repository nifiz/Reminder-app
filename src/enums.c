#include "enums.h"

const char *COMMAND_STRING_TABLE[] = {
    FOREACH_COMMAND(GENERATE_STRING)
};

const char *FLAG_STRING_TABLE[] = {
    FOREACH_FLAG(GENERATE_STRING)
};

const char *PRIORITY_STRING_TABLE[] = {
    FOREACH_PRIORITY(GENERATE_STRING)
};

/* TODO */

bool FlagMessageLoadParam(const char* param) {return true;}
bool FlagColorLoadParam  (const char* param) {return true;}
bool FlagWhenLoadParam   (const char* param) {return true;}
bool FlagFreqLoadParam   (const char* param) {return true;}
bool FlagIdLoadParam     (const char* param) {return true;}

#undef FOREACH_COMMAND
#undef FOREACH_FLAG
#undef FOREACH_PRIORITY
#undef GENERATE_ENUM
#undef GENERATE_STRING