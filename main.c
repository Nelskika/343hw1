#include <stdio.h>
#include "file.c"
#include <stdlib.h>
struct wav_file* wav;
/**
Reverse a wav file, takes 2 Arguments file to be reversed and new file 
@author Kameron Nelski 
@version 2/3/20202
**/
int main(int argc, char* argv[]){

	char* file; //filename 
	char* storage; // storage buffer
	
	//Checks correct number of arguments
	if(argc !=3){
		printf("%s\n","Use case: in wav file, out wav file" );
		printf("%s\n","exiting" );
		exit(1);
	}
	file = argv[1];

	printf("%s%s\n","File: ",  file);
	
	//Calls read file and saves the return into long size
	long size = read_file(file, &storage);
	
	//parses the buffer into a wav struct
	wav = parse(storage);
	
	//temporary buffer
	char* temp = malloc(size);
	
	if(temp ==NULL){
		printf("%s\n","malloc error, exiting");
		exit(1);
	}
	
	//copies the header of storage buffer to temp buffer
	for(int i = 0;i <= 43; i++){
		temp[i] = storage[i];

	}

	//end of the file
	int end = size;

	//size of the data minus header
	size = size -44;
	
	//checks bits per sample of wav, if 16 run first part, if 8 run other
	if(wav->bps == 16){
	for (int i = 0; i <= size; i= i +2)
		{
		temp[44+ i] = storage[end- i];
		temp[44 + i+ 1] = storage[end-(i +1) ];
		
		}
	}else{
		for (int i = 0; i <= size; i++)
		{
		temp[43+ i] = storage[end- i];
		}
	}


	//writes to file
	write_file(argv[2],temp,size);
	
	//frees memory
	free(temp);
	free(storage);
	free(wav);

}
