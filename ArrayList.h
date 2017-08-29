//
//  ArrayList.h
//  OpenDMX
//
//  Created by Patrick  Marx on 21.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h
#include <stdlib.h>

typedef struct{
    size_t size;
    void** data;
}ArrayList;

/**
 * Creates the arraylist
 **/
ArrayList* create();

/**
 * Set a value to the list
 **/
void setData(ArrayList *list, void** data, int max, int clearData);

void add(ArrayList *list, void* elem);

void *ArrayList_get(ArrayList *list, int index);

//Returns the size of the internal Array in the memory
size_t getSizeOf(ArrayList *list);

//returns the Elements in the arraylist
size_t getSize(ArrayList *list);

void ArrayList_remove(ArrayList *list, int index, int freeit);

void ArrayList_clear(ArrayList *list);

void deallocate(ArrayList *list);

int getIndex(ArrayList *list, void *elem);


#endif /* ArrayList_h */
