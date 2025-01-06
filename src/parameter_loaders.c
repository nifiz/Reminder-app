#include "parameter_loaders.h"

/* TODO */

void loadParameter(const RawParameter* source, Parameter* destination)
{
    /* initialization in case anything goes wrong ig */
    destination->flag = source->flag;
    destination->data = NULL;

    switch (source->flag)
    {
    case msg:
        FlagMessageLoadParam(source->param, destination);
        break;
    case color:
        FlagColorLoadParam  (source->param, destination);
        break;
    case when:
        FlagWhenLoadParam   (source->param, destination);
    case freq:
        FlagFreqLoadParam   (source->param, destination);
        break;
    case id:
        FlagIdLoadParam     (source->param, destination);
        break;
    default:
        break;
    }
}

bool FlagMessageLoadParam(const char* param, Parameter* dest) 
{
    // invalid strcpy - dest needs to be malloc'ed!
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

