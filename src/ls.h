#ifndef _LS_H
#define _LS_H

#include "helper.h"
using namespace std;

void ls(string path){
    DIR *dir = opendir(path.c_str());
    if(!dir){
        perror("Error in path");
        return;
    }

    dirent *pdir = readdir(dir);
    int i = 0;
    while(pdir){
        if(pdir->d_type == DT_DIR){
            if(i%2 == 1)
                print("*"<<(pdir->d_name)<<"*\n");
            else
                print("*"<<(pdir->d_name)<<"*\t\t");
        }else{
            if(i%2 == 1)
                print(pdir->d_name<<"\n");
            else
                print(pdir->d_name<<"\t\t");                
        }
        pdir = readdir(dir);
        i++;
    }
    closedir(dir);
}

#endif