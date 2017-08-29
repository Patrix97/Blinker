//
//  main.c
//  OpenDMX
//
//  Created by Patrick  Marx on 21.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

//ALLE DMX WERTE ALS uint8_t speichern!!!
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include "arduino-serial-lib.h"
#include "dmx.h"
#include "CSV_reader.h"
#include "fixture.h"



const char* port = "/dev/ttys0"; //Actually just for testing

int init(){
   return serialport_init(port, 9600);
}

int main(int argc, const char * argv[]) {
    //int fd = init();
    /*
    uint8_t* universe = calloc(512, sizeof(uint8_t));
    int channel;
    uint8_t value;
    int i;
    
  
    
                printf("Please enter the channel, where you want to set or change a value (Between 1 and 512): ");
                scanf("%i", &channel);
                printf("Please enter a value between 0 and 255: ");
                scanf("%hhu", &value);
                
                set_dmx(channel, value, universe);
                for(i = 0; i < 512; i++){
                    printf("Send channel %i\n", i+1);
                    serialport_writebyte(fd, universe[i]);
                }*/
    
    FILE* stream = fopen("/Users/patrickmarx/Desktop/DMX/ODMX/OpenDMX/OpenDMX/64B.csv", "r");
    
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Field 3 would be %s\n", get_field(tmp, 1));
        // NOTE strtok clobbers tmp
        free(tmp);
    }
    
        return 0;
}
