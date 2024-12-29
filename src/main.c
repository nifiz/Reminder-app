#include <stdio.h>
#include "parser.h"
#include <../headers/enums.h>

int main(int argc, char** argv) {

    Command givenCommand = validateCommand(argv[1]);

    return 0;
}