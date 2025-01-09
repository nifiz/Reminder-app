#ifndef PARAMETER_LOADERS_H
#define PARAMETER_LOADERS_H

#include "structs.h"
#include "enums.h"
#include "request_structs.h"

void loadParameter(const RawParameter* source, Parameter* destination);
void FlagMessageLoadParam(const char* param, Parameter* dest, uint64_t dataLength);
void FlagColorLoadParam  (const char* param, Parameter* dest, uint64_t dataLength);
void FlagWhenLoadParam   (const char* param, Parameter* dest, uint64_t dataLength);
void FlagFreqLoadParam   (const char* param, Parameter* dest, uint64_t dataLength);
void FlagIdLoadParam     (const char* param, Parameter* dest, uint64_t dataLength);



#endif