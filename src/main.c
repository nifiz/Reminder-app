#include <stdio.h>
#include "../headers/parser.h"
#include "../headers/enums.h"
#include "../headers/request_structs.h"

#define EXECUTABLE_NAME "test"

int main(int argc, char** argv) {

    if (argc == 1) 
    {
        printf("Invalid command passed.\n"); 
        printf("For help type ./%s help\n", EXECUTABLE_NAME);
        return 0;
    }

    Command c = validateCommand(argv[1]);

    RawParameterCollection rpc = structifyParams(argc, argv);

    Request r  = createRequest(&rpc, c);

    getchar();

}