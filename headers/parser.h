#ifndef PARSER_H
#define PARSER_H

#include "structs.h"

Command validateCommand(const char* command);
RawParameterCollection structifyParams(int argc, char** argv);
static Flag validateFlag(const char* flag);
static bool loadParameter(Flag f, const char* parameter, Parameter* dest);
Request createRequest(const RawParameterCollection* rpc);

#endif