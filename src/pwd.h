#ifndef PWD_H
#define PWD_H

#include "helper.h"

string pwd(bool print=false) {
    char *cwd = new char[PATH_MAX];
    
    if(getcwd(cwd, PATH_MAX*sizeof(char)) != NULL) {

        if(print)
            print(cwd<<"\n");
        return cwd;
    } else {
        return NULL;
    }
}

#endif