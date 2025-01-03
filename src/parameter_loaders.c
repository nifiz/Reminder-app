#include "parameter_loaders.h"

/* TODO */

bool FlagMessageLoadParam(const char* param, Parameter* dest) 
{
    strcpy((char*)dest->data, param);
    dest->flag = msg;
    return true;
}
bool FlagColorLoadParam  (const char* param, Parameter* dest) 
{
    /* Not sure if color should be a hex or an enum - perhaps something else entirely? */
    strcpy((char*)dest->data, param);
    dest->flag = msg;
    return true;
}
bool FlagWhenLoadParam   (const char* param, Parameter* dest) 
{
    /* A bit more complex - we gotta load a tm struct*/



    return true;
}
bool FlagFreqLoadParam   (const char* param, Parameter* dest) {return true;}
bool FlagIdLoadParam     (const char* param, Parameter* dest) {return true;}