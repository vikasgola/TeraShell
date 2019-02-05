#ifndef TOUCH_H
#define TOUCH_H

#include "helper.h"

void touch(string filename){
    ofstream f(filename);
    f.close();
}

#endif