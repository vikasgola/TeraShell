#ifndef CD_H
#define CD_H

#include "helper.h"

void cd(string path){
    if(chdir(path.c_str()) < 0){
        perror("Error in changing directory");
        return;
    }
}

#endif