//
//  FileControl.h
//  Experiments
//
//  Created by Patrick  Marx on 10.09.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#ifndef FileControl_h
#define FileControl_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>


/* ALL METHODS RETURN -1 IF THERE IS AN ERROR! 
 * If everything works fine, the methods return 0.
 */


int swd(); /* Set the working directory to /Users/$USER/Documents/Blinker */
int cwd(); /* Change to the working directory */
char* ret_wd();
#endif /* FileControl_h */
