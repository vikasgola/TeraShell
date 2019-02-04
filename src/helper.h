#ifndef _HELPER_H
#define _HELPER_H

#include<iostream>
#include<algorithm>
#include<dirent.h>
#include <sys/types.h>
#include<string>
#include<vector>
#include<regex>
#include <unistd.h>
#include<limits.h>
using namespace std;

#define print(p_input) std::cout<<p_input

// commands
#define TREE 0
#define PWD 1


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
