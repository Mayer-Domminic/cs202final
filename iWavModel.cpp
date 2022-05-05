#include "iWavModel.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//iWavModel::iWavModel(){}

//virtual iWavModel::~iWavModel(){}
/*virtual FileAttributes iWaveModel::openFile(const std::string &file_name){
	ifstream file(file_name, ios::binary | ios::in);
	if(file.is_open()){
		file.read((char *) &wavHeader, sizeof(wav_header));
		buffer = new short[waveHeader.data_bytes];
		file.read((char*) buffer, waveHeader.data_bytes);

		for (int i = 0; i < waveHeader.data_bytes / waveHeader.sample_alignment; i++){
			soundeData.push_back((float)buffer[i] / MAX_16BIT);
		}
		file.close();
	}	
	else{
		cout << "not able to read file" << endl;
		//return 0;
	}
	delete[] buffer;
}*/

virtual FileAt iWaveModel::readFile(const std::string &file_name){
	int read;
	unsigned char buffer4[4];
	FILE* file = fopen(file_name, "rb");

	if(file == NULL){
		cout << "not able to open file" << endl;
		return 0;
	} else{
		FILE * outputfile = fopen("Echoed_output.wav", "wb");
		//Reads header of file
		size_t bytesRead = fread(&wavHeader, 1, headerSize, file);
		fwrite(&wavHeader, 1, headerSize, outputfile);

		//Reads data
		if(bytesRead > 0){
			sample init_samples[wavHeader.sample_rate];
			long size_of_each_sample = (wavHeader.num_channels * wavHeader.bit_depth);
			read = fread(buffer4, sizeof(buffer4), 1, file);
			unsigned int data_size = buffer4[0] | (buffer4[1] << 8) | (buffer4[2] << 16) | (buffer4[3] << 24);

			long num_samples = (8 * wavHeader.data_bytes) / (waveHeader.num_channels * wavHeader.bit_depth);
		}
	}
	
}
virtual std::vector<std::string> getProcessList()=0;
virtual void setOutPutFileName(const std::string& outputFileName)=0;
virtual void processFile(const std::string& processID)=0;