#include <stdio.h>
#include "../headers/parser.h"
#include "../headers/enums.h"

int main(int argc, char** argv) {

    Command c = validateCommand(argv[1]);

    RawParameterCollection rpc = structifyParams(argc, argv);

    for (uint8_t i = 0; i < rpc.size; i++) {
        loadPa
    }
}