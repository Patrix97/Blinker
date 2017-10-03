//
//  CSV_reader.c
//  OpenDMX
//
//  Created by Patrick  Marx on 25.08.17.
//  Copyright © 2017 Patrick  Marx. All rights reserved.
//

#include "CSV_reader.h"

FILE* fp; 
int lines;
int open_csv(char* filename){
	fp = fopen(filename, "r");
	if(fp == NULL){
		return -1;
	}
	return 0;
}
const char* get_field(char* line, int number)
{
    const char* tok;
    for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")){
        if (!--number)
            return tok;
    }
    return NULL;
}

int get_number_lines(){
	int ch = 0;
	if(fp == 0){
		return 0;
	}
	
	lines++;

	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '\n'){
			lines++;
		}
	}
	return lines;
}

void get_array_from_field(int field, int* a, int* b){
	rev();
	int x = 0;
	while((fscanf(fp,"%d;%d\n", &a[x], &b[x])) != EOF) {
       fprintf(stdout,"Written: %d;%d\n", a[x], b[x]);
       x++;
	}
}

void rev(){
	fseek(fp, 0L, SEEK_SET);
	printf("Reverse\n");
}
