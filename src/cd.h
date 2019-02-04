#ifndef CD_H
#define CD_H

#include "helper.h"

void cd(string path){
    if(path.substr(0,2) == "./" )
        path = pwd() + path.substr(1);
    if(path[0] != '.' && path[0] != '/')
        path = pwd()+ "/" + path;
    if(chdir(path.c_str()) < 0){
        perror("Error in changing directory");
        return;
    }
}

#endif