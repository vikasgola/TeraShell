#ifndef HELPER_H
#define HELPER_H

#include<iostream>
#include<algorithm>
#include<dirent.h>
#include<sys/types.h>
#include<string>
#include<vector>
#include<regex>
#include <unistd.h>
#include<limits.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

#define print(p_input) std::cout<<p_input


vector<string> tokenize(string input){
    vector<string> command;
    stringstream full_command(input);
    string intermediate; 
    string temp = "";

    while(getline(full_command, intermediate, ' ')) {
        if(intermediate[intermediate.length()-1] == '\\'){
            temp += intermediate.substr(0,intermediate.length()-1) + " ";
        }else if(temp != ""){
            temp += intermediate;            
            command.push_back(temp);
            temp = "";
        }else{
            command.push_back(intermediate);
        }
    }
    return command;
}

#endif
