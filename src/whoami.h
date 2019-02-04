#ifndef WHOAMI_H
#define WHOAMI_H

#include<pwd.h>
#include "helper.h"

string whoami(bool print=false){
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid (uid);
    if(pw){
        if(print)
            print((pw->pw_name)<<"\n");
        return string(pw->pw_name);
    }
}

#endif