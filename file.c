#include <stdio.h>
#include<stdlib.h>
#include "wav.c"

/**
Reads in a wav file
@param filename name of initial file
@param buffer pointer to pointer of storage buffer
@author Kameorn Nelski
@version 2/3/2020
**/
size_t read_file(char* filename, char **buffer){
	
	long size;
	FILE* inFile;
	
	//opens file
	inFile = fopen(filename, "rb");
	
	if(inFile == NULL){
		printf("%s%s%s\n", "No file named ", filename , " exiting.");
		exit(1);
	}

	//seeks end of file to get file size
	fseek(inFile,0,SEEK_END);
	size = ftell(inFile);
	rewind(inFile);

	//mallocs required file size to  storage buffer
	*buffer = malloc(size);
	if(*buffer ==NULL){
		printf("%s\n","malloc error, exiting");
		exit(1);
	}
	
	 
	//reads infile into buffer 
	fread(*buffer,1,size,inFile);
	
	return size;
	}

/**
Writes reversed file to file
@param filename name of file to be written to
@param buffer data to be saved
@param size size of datat to be writen
**/
size_t write_file(char* filename, char * buffer, size_t size){

	FILE* test;
	
	test = fopen(filename,"wb");

	if(test == NULL){
		printf("%s%s%s\n", "No file named ", filename , " exiting.");
		exit(1);
	}
		
	fwrite(buffer,1,size+44,test);
	
	fclose(test);
	
	return(size);

}