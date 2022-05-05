#include "iWavModel.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

FileAttributes openFile(const string &filename){
	ifstream file(filename, ios::binary | ios::in);
	short* buffer = nullptr;

	if(file.is_open()){

		file.read((char*)&header, 20);
		file.read((char*)&header + 20, header.subchunk1_size);
		file.read((char*)&header + 20 + header.subchunk1_size, 8);

		buffer = new short[header.data_bytes];
		file.read((char*)buffer, header.data_bytes);

		int maxSize = pow(2, header.bits_per_sample - 1);
		int upperBound = header.data_bytes / header.block_align * header.num_channels;

		if(header.num_channels == 1){
			for(int i = 0; i < upperBound; i++){
				data[0].push_back((float)buffer[i] / maxSize); //second arg in power is max value of the bitrate
			}
		} else {
			data.push_back({});
			for(int i = 0; i < upperBound; i++){
				if(i % 2 == 0) {
					data[0].push_back((float)buffer[i] / maxSize); //left ear bit 1
				} else {
					data[1].push_back((float)buffer[i] / maxSize); //right ear bit 1
				}
			}
		}
		file.close();
	}
	delete[] buffer;
}