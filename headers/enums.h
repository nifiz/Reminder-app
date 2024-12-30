#ifndef ENUMS_H
#define ENUMS_H

#include <stdbool.h>
#include <string.h>

/* Synchronized enum & corresponding string table 
creation macro for later use. */ 

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

/* Command enum */

#define FOREACH_COMMAND(COMMAND) \
        COMMAND(add)   \
        COMMAND(delete)  \
        COMMAND(edit)   \
        COMMAND(list)  \
        COMMAND(error)  \
        COMMAND(help)

#define COMMAND_AMOUNT 6

typedef enum {
    FOREACH_COMMAND(GENERATE_ENUM)
} Command;

extern const char *COMMAND_STRING_TABLE[];

/* Flag enum */

#define FOREACH_FLAG(FLAG) \
        FLAG(msg)   \
        FLAG(color)  \
        FLAG(when)   \
        FLAG(freq) \
        FLAG(id) \
        FLAG(badFlag)

#define FLAG_AMOUNT 6

typedef enum 
{
    FOREACH_FLAG(GENERATE_ENUM)
} Flag;

extern const char *FLAG_STRING_TABLE[];

bool FlagMessageLoadParam(const char* param);
bool FlagColorLoadParam(const char* param);
bool FlagWhenLoadParam(const char* param);
bool FlagFreqLoadParam(const char* param);

/* Priority enum */

#define FOREACH_PRIORITY(PRIORITY) \
        PRIORITY(unimportant)   \
        PRIORITY(normal)  \
        PRIORITY(critical) \
        PRIORITY(badPriority)

#define PRIORITY_AMOUNT 4

typedef enum
{
    FOREACH_PRIORITY(GENERATE_ENUM)
} Priority;

extern const char *PRIORITY_STRING_TABLE[];

#endif