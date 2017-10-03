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



int open_csv(char* filename);
const char* get_field(char* line, int number);
int get_number_lines();
void get_array_from_field(int field, int* a, int* b);
void rev();
#endif /* CSV_reader_h */
