//
//  ArrayList.c
//  OpenDMX
//
//  Created by Patrick  Marx on 21.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "ArrayList.h"

#define NDEBUG

ArrayList* create(){
    ArrayList *list = malloc(sizeof(ArrayList));
    assert(list!= NULL);
    list->size = 0;
    list->data = calloc(2, sizeof(void));
    assert(list->data != NULL);
    list->data[0] = NULL;
    return list;
}

void setData(ArrayList *list, void** data, int max, int clear_data){
    clear_data ? ArrayList_clear(list) : NULL;
    list->data = data;
    list->size = max;
}

void add(ArrayList *list, void* elem){
    void** newData = realloc(list->data, getSizeOf(list));
    assert(newData != NULL);
    newData[list->size] = elem;
    setData(list, newData, list->size+1, 0);
}

void* ArrayList_get(ArrayList *list, int index){
    return list->data[index];
}

size_t getSizeOf(ArrayList *list){
    return sizeof(*list->data);
}

size_t getSize(ArrayList *list){
    return list->size;
}

void ArrayList_remove(ArrayList *list, int index, int freeit){
    if(index > list->size-1){
        return;
    }
    
    if(list->size == 1){
        ArrayList_clear(list);
        return;
    }
    
    if(freeit){
        free(ArrayList_get(list, index));
    }
    
    for(int i = index; i < list->size; i++){
        if(i == list->size-1){
            list->data[i] = NULL;
        }else{
            list->data[i] = list->data[i+1];
        }
    }
    
    void** newData = realloc(list->data, getSizeOf(list));
    --list->size;
    assert(newData != NULL);
    setData(list, newData, list->size, 0);
}

void ArrayList_clear(ArrayList *list){
    list->size = 0;
    free(list->data);
    list->data = NULL;
}

void deallocate(ArrayList *list){
    if(list->data != NULL){
        free(list->data);
    }
    free(list);
}

int getIndex(ArrayList *list, void* elem){
    for(int i = 0; i < list->size; i++){
        if(elem == ArrayList_get(list, i)){
            return i;
        }
    }
    return -1;
}
