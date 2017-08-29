//
//  fixture.h
//  OpenDMX
//
//  Created by Patrick  Marx on 29.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#ifndef fixture_h
#define fixture_h
#include <stdint.h>

/* This enum defines the numbers for the diferent functions can be used by a DMX fixture.
 * The simpelest fixture is a PAR-Can with one Dimmer(1) channel.
 * A more complex fixture is a moving head with various functions for gobos, pan, tilt, dimmer and color.
 */
typedef enum{
    Dim = 1,
    Red = 2,
    Green = 3,
    Blue = 4,
    Amber = 5,
    White = 6,
    UV = 7,
    Pan = 8,
    Tilt = 9,
    Focus = 10,
    Gobo = 11,
    Shutter = 12
}function;

/* This struct defines the structure of a specific channel from a fixture.
 * Every channel has an ID, which is used to locate a function in a fixture. If the dimmer is on channel one of a
 * fixture, it must be the ID 1. The lowest possible id is 1 and the maximal possible is 512.
 * Every channel has a function (from the enum above) and a value between 0 and 255.
 */
typedef struct{
    int ch_id;
    function f;
    uint8_t value;
}channel;
#endif /* fixture_h */
