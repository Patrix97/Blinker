//
//  CSV_reader.h
//  OpenDMX
//
//  Created by Patrick  Marx on 25.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#ifndef CSV_reader_h
#define CSV_reader_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row_count;


const char* get_field(char* line, int number);

#endif /* CSV_reader_h */
