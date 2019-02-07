#ifndef RUN_H
#define RUN_H

#include "helper.h"

bool compare_commands(pair<int,string> a, string b){
    return a.second == b;
}

void run(vector<string> arg){
    auto index = find_if(COMMANDS.begin(), COMMANDS.end(), bind(compare_commands, std::placeholders::_1, arg[1]));

    if(index == COMMANDS.end()){
        print("No such file exist in PATH\n");
        return;
    }else{
        arg[1] = PATH[(*index).first]+(*index).second;
    }

    int cpid = fork();

    if(cpid == -1){
        perror("Error in creating child process.");
    }else if(cpid == 0){
        if(arg.size() > 2){
            char *argv[arg.size()];
            for(int i = 1;i<arg.size();i++){
                argv[i-1] = (char*)arg[i].c_str();
            }
            argv[arg.size()-1] = NULL;
            execvp(arg[1].c_str(), argv);
        }else{
            char *argv[] = {NULL};
            execvp(arg[1].c_str(), argv);
        }
        // exit(EXIT_SUCCESS);
    }else{
        wait(0);
    }
}

#endif