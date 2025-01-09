#include <stdlib.h>

#include "../headers/parameter_loaders.h"
/* TODO */

void loadParameter(const RawParameter* source, Parameter* destination)
{
    /* initialization in case anything goes wrong ig */
    destination->flag = source->flag;
    destination->data = NULL;

    switch (source->flag)
    {
    case msg:
        FlagMessageLoadParam(source->param, destination, source->paramLen);
        break;
    case color:
        FlagColorLoadParam  (source->param, destination, source->paramLen);
        break;
    case when:
        FlagWhenLoadParam   (source->param, destination, source->paramLen);
    case freq:
        FlagFreqLoadParam   (source->param, destination, source->paramLen);
        break;
    case id:
        FlagIdLoadParam     (source->param, destination, source->paramLen);
        break;
    default:
        break;
    }
}
// **Allocates* memory and sets a valid Parameter pointed to by destination
// might return a NULL pointer in case memory allocation fails
void FlagMessageLoadParam(const char* source, Parameter* destination, uint64_t dataLength) 
{   
    /* 'source' is already a null terminated string. */
    destination->data = malloc(sizeof(char) * dataLength);
    if (destination->data == NULL) return;
    strcpy_s(destination->data, dataLength * sizeof(char), source);
    return true;
}
void FlagColorLoadParam  (const char* param, Parameter* destination, uint64_t dataLength) 
{
    /* Not sure if color should be a hex or an enum - perhaps something else entirely? */
    destination->data = malloc(sizeof(char) * dataLength);
    if (destination->data == NULL) return;
    strcpy((char*)destination->data, param);
    destination->flag = color;
    return true;
}
void FlagWhenLoadParam   (const char* param, Parameter* dest, uint64_t dataLength) 
{
    // TODO - error checking for provided numbers, currently years like 2147483647 are possible

    dest->data = malloc(sizeof(struct tm));

    struct tm* s_tm = dest->data;

    if (dest->data == NULL)
    {
        dest->flag = error;
        return;
    }
    dest->flag = when;    

    printf("raw param: %s\n", param);
    /* 19 characters, in the following order: "DD-MM-YYYY:HH:MM:SS" */
    char * token = strtok(param, "\".:-");
    s_tm->tm_mday = atoi(token);

    token = strtok(NULL, "\".:-");
    s_tm->tm_mon = (atoi(token) - 1); // 0 indexed months.

    token = strtok(NULL, "\".:-");
    s_tm->tm_year = (atoi(token) - 1900); // Years since 1900.

    token = strtok(NULL, "\".:-");
    s_tm->tm_hour = atoi(token);

    token = strtok(NULL, "\".:-");
    s_tm->tm_min = atoi(token);
    
    token = strtok(NULL, "\".:-");

    if (token == NULL) // seconds omitted
    {
        token = "0";
    }
    s_tm->tm_sec = atoi(token);

    return;
}
void FlagFreqLoadParam   (const char* param, Parameter* dest, uint64_t dataLength) 
{
    FlagWhenLoadParam(param, dest, dataLength);

    if (dest->data == NULL) dest->flag = error;

    else dest->flag = freq;

    return;
}
void FlagIdLoadParam     (const char* param, Parameter* dest, uint64_t dataLength) 
{
    dest->flag = id;
    dest->data = malloc(sizeof(uint64_t));
    if (!dest->data == NULL) // i like to be explicit that's all
    {
        dest->flag = error;
        return;
    }
    void* foo = dest->data;

    *(uint64_t*)(dest->data) = _atoi64(param);
    
    return;
}