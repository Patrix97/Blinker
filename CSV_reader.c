//
//  CSV_reader.c
//  OpenDMX
//
//  Created by Patrick  Marx on 25.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#include "CSV_reader.h"

const char* get_field(char* line, int number)
{
    const char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--number)
            return tok;
    }
    return NULL;
}
