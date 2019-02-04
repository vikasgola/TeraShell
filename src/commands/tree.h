#ifndef TREE_H
#define TREE_H

#include "helper.h"

void dfs(string path, int d, int ld = -1){
    if(d > ld && ld != -1) return;

    DIR *dir = opendir(path.c_str());
    if(!dir){
        perror("Error in opening directory");
        return;
    }

    string sdepth;    
    for(int i=0;i<d;i++)
        sdepth += "\t";

    // sdepth += "";
    dirent *pdir = readdir(dir);
    while(pdir){
        if( (string)pdir->d_name != "." && (string)pdir->d_name != ".." ){
            print(sdepth);
            if(pdir->d_type == DT_DIR){
                print("*"<<(pdir->d_name)<<"*\n");
                dfs(path+"/"+pdir->d_name, d+1, ld);
            }else{
                print(pdir->d_name<<"\n");
            }
        }
        pdir = readdir(dir);
    }
    closedir(dir);
}

struct files {
    string filename;
    int depth;
    bool isDir;
};

vector<files> bfs(string path, int d, int ld = -1){
    DIR *dir = opendir(path.c_str());
    if(!dir){
        print(path.c_str());
        perror("Error in opening directory");
    }
    vector<files> filelist;

    dirent *pdir = readdir(dir);
    while(pdir){
        if( (string)pdir->d_name != "." && (string)pdir->d_name != ".." ){
            files temp;
            temp.isDir = false;
            
            if(pdir->d_type == DT_DIR){
                temp.isDir = true;
            
                vector<files> tlist;
                if( ld > d || ld == -1){
                    tlist = bfs(path+"/"+pdir->d_name, d+1, ld);
                } 
                filelist.insert(filelist.end(), tlist.begin(), tlist.end());
            }
            temp.depth = d;
            temp.filename = pdir->d_name;
            filelist.push_back(temp);
        }
        pdir = readdir(dir);
    }
    closedir(dir);
    return filelist;
}

bool compare(files a, files b){
    return (a.depth < b.depth);
}

void printFileList(vector<files> all_list){
    sort(all_list.begin(), all_list.end(), compare);
    for(auto file: all_list){
        int k = file.depth;
        string out = "";

        while(k--) out += "\t";
        if(file.isDir){
            print(out<<"*"+file.filename+"*"<<"\n");
        }else{
            print(out<<file.filename<<"\n");
        }
    }
}

int tree(int argc, vector<string> argv){
    if(argc == 2){
            dfs(argv[1], 0);        
    }if(argc == 3){
        if(argv[2] == "--dfs"){
            dfs(argv[1], 0);
        }else if(argv[2] == "--bfs"){
            vector<files> all_list = bfs(argv[1], 0);
            printFileList(all_list);
        }
    }else if(argc == 4){
        if(argv[2] == "--dfs"){
            dfs(argv[1], 0, atoi(argv[3].c_str()));  
        }else if(argv[2] == "--bfs"){
            vector<files> all_list = bfs(argv[1], 0, atoi(argv[3].c_str()));
            printFileList(all_list);
        }
    }else{
        print("Please check usage.\n");
        return 0;
    }
    return 1;
}

#endif