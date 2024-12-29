#ifndef ENUMS_H
#define ENUMS_H

typedef enum 
{
    msg, color, when, freq
} Flag;

typedef enum
{
    unimportant, normal, critical
} Priority;

/* Synchronized enum & corresponding string table 
creation macro for later use. */ 

#define FOREACH_COMMAND(COMMAND) \
        COMMAND(add)   \
        COMMAND(delete)  \
        COMMAND(edit)   \
        COMMAND(list)  \
        COMMAND(error)  \
        COMMAND(help)

#define COMMAND_AMOUNT 6

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

typedef enum {
    FOREACH_COMMAND(GENERATE_ENUM)
} Command;

extern const char *COMMAND_STRING_TABLE[];

#endif