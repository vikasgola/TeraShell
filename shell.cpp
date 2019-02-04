#include "src/helper.h"
#include "src/tree.h"
#include "src/colors.h"
#include "src/pwd.h"
#include "src/ls.h"
#include "src/cd.h"
#include "src/whoami.h"
#include "src/hostname.h"

int main(int argc, char *argv[]){
    string input;

    print("Welcome to 21st Century Shell\n");
    print(bold(color_blue(whoami()+"@"+hostname()))<<":"<<bold(color_red(pwd())<<color_green(">> ")));
    string default_dir = pwd();

    
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
            }
            print(bold(color_blue(whoami()+"@"+hostname()))<<":"<<bold(color_red(pwd())<<color_green(">> ")));
        }
    }

    print("GoodBye!\n");
    return 0;
}