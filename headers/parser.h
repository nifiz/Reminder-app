#ifndef PARSER_H
#define PARSER_H

#include "structs.h"

Command validateCommand(const char* command);
static Flag validateFlag(const char* flag);

#endif