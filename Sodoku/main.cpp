//#include "Puzzle.h"
#include <iostream>

#include "Solution.h"
#include "Constructor.h"


int main(int argc, const char * argv[]) {

    if (strcmp(argv[1], "-c")  == 0) {
        
        construct(argv[2]);

    } else if (strcmp(argv[1], "-s")  == 0) {
        
        solve(argv[2]);
        
    }
    
    return 0;
}
