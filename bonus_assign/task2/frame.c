/******************************************************
* File: frame.c
*
* This is the frame struct implementation
*
******************************************************/
#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
static void load_frame(frame_t *f, char *path){
	//your code here
	// path is the pathname to an ascii file, we have to open the ascii file, and read the content
	// in line by line and store it in the frame->content
	// here is an example of reading line-by-line from path
	// FILE * fp;
    	// char * line = NULL; 
	//fp = fopen(path, "r");
    	//if (fp == NULL)
        	//exit(EXIT_FAILURE);
  	FILE* fp;
	char* line = NULL;
	fp = fopen(path, "readFile");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}
size_t sizeable;
size_t length;

    	//while ((read = getline(&line, &len, fp)) != -1) {
  int retrieve = getline(&line, &sizeable, fp);
	assert(a!=-1);
  f->rep_counter = atoi(line);
        	//printf("Retrieved line of length %zu:\n", read);
        	//printf("%s", line); //this line is NOT your code

  char* byteNum=malloc(sizeof(char));
	byteNum[0] = '\0';
	size_t fLen = 0;
	while ((length = getline(&line, &sizeable, fp)) != -1) { 
		byteNum = realloc(byteNum, (fLen+line_len+1));//could repalce strlen(line)+1 by len?
		strcpy(byteNum+fLen,line);
		fLen += length;
		//your task is not to print the line, instead, you need to save the line to
		//frame->content
  free(line);
	f->content = file_bytes
    	//}
	//fclose(fp);
  fclose(fp);
	//also keep in mind, the first line is the repetition counter.
	//f->rep_counter = ...
	return;
}

frame_t * frame_new(char *pathname, int id) {
	frame_t * f = (frame_t *) malloc(sizeof(frame_t));
	if(!f) {
		perror("OOM, alloc failed\n");
		return 0;
	}
	f->id = id;
	load_frame(f, pathname);
	return f;
}

void frame_delete(frame_t * f) {
	free(f->content);
	free(f);
}

char* frame_get_content (frame_t *f){
	return f-> content;
}
int frame_get_rep_counter(frame_t * f){
	return f-> rep_counter;
}
int frame_get_id(frame_t *f){
	return f-> id;
}

