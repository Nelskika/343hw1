/**
Wave header struct
@author Kameron Nelski
@version 2/3/2020
**/
struct wav_file{

	char riff[4];
	int chunkSize;
	char  wave[4];
	char fmt[4];
	int fmtLength;
	short fmtType;
	short chans;
	int sampleRate;
	int byteRate;
	short blockAlign;
	short bps;
	char dataBeg[4];
	int dataSize;
	char* data;

};
struct wav_file* parse(char* contents);
