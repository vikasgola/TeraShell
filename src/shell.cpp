#include "commands/helper.h"
#include "commands/tree.h"
#include "commands/colors.h"
#include "commands/pwd.h"
#include "commands/ls.h"
#include "commands/cd.h"
#include "commands/whoami.h"
#include "commands/hostname.h"
#include "commands/cat.h"
#include "commands/date.h"
#include "commands/touch.h"
#include "commands/cp.h"
#include "commands/mv.h"
#include "commands/run.h"


vector<string> PATH;
vector<pair<int, string>> COMMANDS;

void readConfig(){
    ifstream pathfile("config/path.txt");
    if(!pathfile.is_open()){
        print("config file not found.\n");
        // perror("Error in opening config file.");
        // exit(EXIT_FAILURE);
    }

    string location;
    while(getline(pathfile, location)){
        if(location.substr(0,2) == "./" )
            location = pwd() + location.substr(1);
        if(location[0] != '.' && location[0] != '/')
            location = pwd()+ "/" + location;

        PATH.push_back(location);
        vector<files> fileslist = bfs(location, 0, 1);
        
        pair<int, string> temp;
        for(auto a: fileslist){
            if(!a.isDir){
                temp.first = PATH.size()-1;
                temp.second = a.filename;
                COMMANDS.push_back(temp);
            }
        }
    }
}

int main(int argc, char *argv[]){
    string input;

    print("Welcome to 21st Century Shell\n");
    print(bold(color_blue(whoami()+"@"+hostname()))<<":"<<bold(color_red(pwd())<<color_green(">> ")));
    string default_dir = pwd();

    readConfig();

    while(getline(cin, input)){
        if(input == "exit"){
            break;
        }else{
            vector<string> command = tokenize(input);
            
            if(command[0] == "tree"){
                tree(command.size(), command);
            }else if(command[0] == "pwd"){
                pwd(true);
            }else if(command[0] == "ls"){
                if(command.size() > 1)
                    ls(command[1]);
                else
                    ls(".");
            }else if(command[0] == "cd"){
                if(command.size() > 1)
                    cd(command[1]);
                else
                    cd(default_dir);
            }else if(command[0] == "whoami"){
                whoami(true);
            }else if(command[0] == "hostname"){
                hostname(true);
            }else if(command[0] == "cat"){
                if(command.size() > 1)
                    cat(command[1]);
                else
                    print("Please specify the file name.\n");
            }else if(command[0] == "echo"){
                if(command.size() > 1)
                    print(command[1]<<endl);
            }else if(command[0] == "date"){
                date();
            }else if(command[0] == "touch"){
                if(command.size() > 1)
                    touch(command[1]);
            }else if(command[0] == "cp"){
                if(command.size() > 2)
                    cp(command[1],command[2]);
            }else if(command[0] == "mv"){
                if(command.size() > 2)
                    mv(command[1],command[2]);
            }else if(command[0] == "rm"){
                if(command.size() > 1)
                    remove(command[1].c_str());
            }else if(command[0] == "clear"){
                system("clear");
            }else if(command[0] == "rmdir"){
                if(command.size() > 1)
                    rmdir(command[1].c_str());
            }else if(command[0] == "mkdir"){
                if(command.size() > 1)
                    if (mkdir(command[1].c_str(), 0777) == -1)
                        perror("Error in creating dir.");
            }else if(command[0] == "run"){
                if(command.size() > 1)
                    run(command);
            }else{
                print("No command "<<command[0]<<" found!"<<endl);
            }
            print(bold(color_blue(whoami()+"@"+hostname()))<<":"<<bold(color_red(pwd())<<color_green(">> ")));
        }
    }

    print("GoodBye!\n");
    return 0;
}