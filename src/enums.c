#include <time.h>
#include <stdlib.h>
#include "../headers/enums.h"
#include "../headers/request_structs.h"


const char *COMMAND_STRING_TABLE[] = {
    FOREACH_COMMAND(GENERATE_STRING)
};

const char *FLAG_STRING_TABLE[] = {
    FOREACH_FLAG(GENERATE_STRING)
};

const char *PRIORITY_STRING_TABLE[] = {
    FOREACH_PRIORITY(GENERATE_STRING)
};

#undef FOREACH_COMMAND
#undef FOREACH_FLAG
#undef FOREACH_PRIORITY
#undef GENERATE_ENUM
#undef GENERATE_STRING