#ifndef PARAMETER_LOADERS_H
#define PARAMETER_LOADERS_H

#include "structs.h"
#include "enums.h"
#include "request_structs.h"

bool FlagMessageLoadParam(const char* param, Parameter* dest);
bool FlagColorLoadParam  (const char* param, Parameter* dest);
bool FlagWhenLoadParam   (const char* param, Parameter* dest);
bool FlagFreqLoadParam   (const char* param, Parameter* dest);
bool FlagIdLoadParam     (const char* param, Parameter* dest);



#endif