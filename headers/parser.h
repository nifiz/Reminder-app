#ifndef PARSER_H
#define PARSER_H

#include "structs.h"

Command validateCommand(const char* command);
RawParameterCollection structifyParams(int argc, char** argv);
static Flag validateFlag(const char* flag);

#endif