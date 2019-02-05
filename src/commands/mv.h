#ifndef MV_H
#define MV_H

#include "helper.h"

void mv(string filename, string copiedfilename){
    ifstream f(filename);

    if(f.is_open()){
        ofstream f2(copiedfilename);
        if(f2.is_open()){
            f2 << f.rdbuf();
            f2.close();
            remove(filename.c_str());
        }
    }else{
        perror("Error in opening file.");
    }
    f.close();
}

#endif