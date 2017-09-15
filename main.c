//
//  main.c
//  OpenDMX
//
//  Created by Patrick  Marx on 21.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

//ALLE DMX WERTE ALS uint8_t speichern!!!
#include <sys/types.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include "arduino-serial-lib.h"
#include "dmx.h"
#include "CSV_reader.h"
#include "fixture.h"
#include "FileControl.h"
#include "ArrayList.h"
#include "colors.h"



const char* port = "/dev/ttys0"; //Actually just for testing
int fd;
DIR* dir;
struct dirent *dirzeiger;

char* wd;
char* fix_folder;

int init(){
    
    int wd1 = swd();
    int wd2 = cwd();
    wd = ret_wd();
    printf("%sINIT%s %s>>%s Working directory: %s\n", BLUE, RESET, GREEN, RESET, wd);
    fix_folder = wd;
    fix_folder = strcat(wd, "/Fixtures");
    printf("%sINIT%s %s>>%s Fixture Folder: %s\n", BLUE, RESET, GREEN, RESET, fix_folder);
    fd = serialport_init(port, 9600);
    printf("%sINIT%s %s>>%s Serial Connection open!\n", BLUE, RESET, GREEN, RESET);
    

    return wd1 == 1 || wd2 == 1 ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    if(init() != 0){
        fprintf(stderr, "%sERROR: %s Something in init() went wrong", RED, RESET);
        return EXIT_FAILURE;
    }
    
    uint8_t* universe = calloc(512, sizeof(uint8_t));
    int channel;
    uint8_t value;
    int i;

    
    /*
    FILE* stream = fopen("/Users/patrickmarx/Desktop/DMX/ODMX/OpenDMX/OpenDMX/64B.csv", "r");
    
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Field 3 would be %s\n", get_field(tmp, 1));
        // NOTE strtok clobbers tmp
        free(tmp);
    }*/
    
    char* menu = malloc(sizeof(char));
    ArrayList *fix_list = create();
    char* fix_folder = wd;
    while(1){
        printf("%sMENU%s\n"
               "s: Send DMX\n"
               "l: load Fixture\n"
               "u: Show Universe\n"
               "q: Quit\n", RED, RESET);
        scanf("%s", menu);
        
        switch (menu[0]) {

            /*
             * Setting DMX-Values
             */
            case 's':
                printf("Please enter the channel, where you want to set or change a value (Between 1 and 512): ");
                scanf("%i", &channel);
                printf("Please enter a value between 0 and 255: ");
                scanf("%hhu", &value);
                
                universe = set_dmx(channel, value, universe);
                break;

            /* Quit the program */
            case 'q':
                return EXIT_SUCCESS;

            /* Load a Fixture */
            case 'l':
                
                
                ArrayList_clear(fix_list);
                if((dir = opendir(fix_folder)) != NULL){
                    while((dirzeiger=readdir(dir)) != NULL){
                        /* Skipping the "unimportant" files */
                        if(strcmp((*dirzeiger).d_name, ".")){
                            continue;
                        }

                        if(strcmp((*dirzeiger).d_name, "..")){
                            continue;
                        }

                        if(strcmp((*dirzeiger).d_name, ".DS_Store")){
                            continue;
                        }

                        add(fix_list, (*dirzeiger).d_name);
                    }
                    
                    for(int i = 0; i < getSizeOf(fix_list); i++){
                        char* entry = (char*)ArrayList_get(fix_list, i);
                        if(entry != NULL){
                            printf("%i: %s\n", i, entry);
                        }else{
                            break;
                        }
                        
                    }
                }
                
                break;

            /* Show the Universe */
            case 'u':
                for(int i = 0; i < 512; i++){
                    printf("%hhu ", universe[i]);
                }
                printf("\n");
                break;
            default:
                printf("Please enter a valid menu entry!");
                break;
        }
        for(i = 0; i < 512; i++){
            serialport_writebyte(fd, universe[i]);
        }
    }
    
        return 0;
}
