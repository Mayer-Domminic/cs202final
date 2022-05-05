#ifndef FEED_BACK_ECHO_FILEATTRIBUTES_H
#define FEED_BACK_ECHO_FILEATTRIBUTES_H

#include <string>

struct FileAttributes {
	std::string file_name;
	
	//RIFF Header
	char riff_header[4];	
	int wav_size;	
	char wave_header[4];	

	//Format Header
	char fmt_header[4];	
	int fmt_chunk_size;	
	short audio_format;	
	short num_channels;	
	int sample_rate;	
	int byte_rate;	
	short sample_alignment;	
	short bit_depth;	

	//Data
	char data_header[4];	
	int data_bytes;	
};

#endif //FEED_BACK_ECHO_FILEATTRIBUTES_H