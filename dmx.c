//
//  dmx.c
//  OpenDMX
//
//  Created by Patrick  Marx on 23.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#include <stdlib.h>
#include "dmx.h"


uint8_t* set_dmx(int channel, uint8_t value, uint8_t* universe){
    if (channel < 512 && value <= 255) {
        universe[channel-1] = value;
    }else{
        printf("Please enter a channel lower than 512 or a value lower or equal 255!\n‚");
    }
    
    return universe;
}
