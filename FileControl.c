//
//  FileControl.c
//  Experiments
//
//  Created by Patrick  Marx on 10.09.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#include "FileControl.h"

const char* working_directory;

int swd(){
    
    uid_t me;
    struct passwd *my_passwd;
    me = getuid();
    my_passwd = getpwuid(me);
    if(!my_passwd){
        fprintf(stderr, "User not found");
        return -1;
    }
    working_directory = my_passwd->pw_dir;
    strcat(working_directory, "/Documents/Blinker");
    return 0;
}

int cwd(){
    if(chdir(working_directory) == -1){
        fprintf(stderr, "Can´t change to the directory");
        return -1;
    }
    return 0;
}

char* ret_wd(){
    return working_directory;
}

