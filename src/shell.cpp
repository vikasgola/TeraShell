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
            }else{
                print("No command "<<command[0]<<" found!"<<endl);
            }
            print(bold(color_blue(whoami()+"@"+hostname()))<<":"<<bold(color_red(pwd())<<color_green(">> ")));
        }
    }

    print("GoodBye!\n");
    return 0;
}