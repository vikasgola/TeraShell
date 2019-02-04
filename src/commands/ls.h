#ifndef LS_H
#define LS_H

#include "helper.h"
using namespace std;

void ls(string path){
    DIR *dir = opendir(path.c_str());
    if(!dir){
        perror("Error in path");
        return;
    }

    dirent *pdir = readdir(dir);
    while(pdir){
        string temp,temp2;
        if(pdir->d_type == DT_DIR){
            temp = "\033[1;33m"+string(pdir->d_name)+"\033[0m";
        }else{
            temp = string(pdir->d_name)+"\033[1;33m"+"\033[0m";
        }

        pdir = readdir(dir);
        if(pdir){
            if(pdir->d_type == DT_DIR){
                temp2 = "\033[1;33m"+string(pdir->d_name)+"\033[0m";
            }else{
                temp2 = string(pdir->d_name)+"\033[1;33m"+"\033[0m";
            }
        }else{
            print(left<<setw(40)<<temp<<endl);
            break;
        }
        
        print(left<<setw(30)<<temp<<setw(50)<<temp2<<endl);
        pdir = readdir(dir);
    }
    closedir(dir);
}

#endif