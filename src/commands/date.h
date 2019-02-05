#ifndef DATE_H
#define DATE_H

#include "helper.h"

void date() {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("%s", asctime(timeinfo));
}

#endif