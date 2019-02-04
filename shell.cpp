#include "src/helper.h"
#include "src/tree.h"
#include "src/colors.h"
#include "src/pwd.h"
using namespace std;

vector<string> tokenize(string input){
    vector<string> command;
    stringstream full_command(input);
    string intermediate; 

    while(getline(full_command, intermediate, ' ')) { 
        command.push_back(intermediate); 
    }
    return command;
}

int main(int argc, char *argv[]){
    string input;

    print("Welcome to 21st Generation Shell\n");
    print(bold(color_red(pwd())<<color_green(">> ")));

    
    while(getline(cin, input)){
        if(input == "exit"){
            break;
        }else{
            vector<string> command = tokenize(input);
            if(command[0] == "tree"){
                tree(command.size(), command);
            }
            print(bold(color_red(pwd())<<color_green(">> ")));
        }
    }

    print("GoodBye!\n");
    return 0;
}