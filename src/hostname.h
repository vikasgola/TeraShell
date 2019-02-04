#ifndef HOSTNAME_H
#define HOSTNAME_H

#include "helper.h"

string hostname(bool print=false) {
    char *hostname = new char[HOST_NAME_MAX];

    if(gethostname(hostname, HOST_NAME_MAX) != -1) {
        if(print)
            print(hostname<<"\n");
        return hostname;
    } else {
        return NULL;
    }
}

#endif