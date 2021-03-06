#include <iostream>
#include "Solution.h"
#include "Constructor.h"
//#define CATCH_CONFIG_MAIN

int main(int argc, const char * argv[]) {

    if (argc != 3) {
        cout << "Command Error, use ' -c INT' or ' -s PATHVARIABLE', try again please" << endl;
        return 0;
    } else if (strcmp(argv[1], "-c")  == 0) {
        construct(argv[2]);
    } else if (strcmp(argv[1], "-s")  == 0) {
        solve(argv[2]);
    } else {
        cout << "Unknown Error, no such command!" << endl;
    }
    
    return 0;
}
