#include "wav.h"
#include <string.h>
struct wav_file* wav;
/**
parses a wav header file
@param contents contents of wav file
@author Kameorn Nelski
@version 2/3/2020
**/
struct wav_file* parse(char* contents){

	//mallocs mem needed
	wav = malloc(sizeof(struct wav_file));
	
	//copies data to wav struct
	memcpy(wav, contents, 44);
	

	
	printf("%s%i\n","File size is ", wav->chunkSize );
	printf("%s%s\n","Format is ", wav->fmt );
	printf("%s%i\n","Format length is ", wav->fmtLength);
	printf("%s%s\n","Format type is ",wav->wave);
	printf("%s%hi\n","Number of channels ", wav->chans );
	printf("%s%i\n", "Sample rat is ", wav->sampleRate);
	printf("%s%i\n","Byte rate is ", wav->byteRate);
	printf("%s%hi\n","Block alignment is ",wav->blockAlign );
	printf("%s%hi\n","Bits per samples is ", wav->bps);
	printf("%s%s\n","Data is ", wav->data);
	printf("%s%i\n", "Data size is ",wav->dataSize );


	return(wav);



}
