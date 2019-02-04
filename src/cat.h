#ifndef CAT_H
#define CAT_H

#include "helper.h"

void cat(string filename){
    ifstream f(filename);

    if (f.is_open())
        print(f.rdbuf());
    print("\n");
}

#endif