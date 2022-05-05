#include "WavManager.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

//retrieve data
void WavManager::setData(vector<vector<float>> newData) {
	soundData = newData;
}

vector<vector<float>> WavManager::getData() {
	return soundData;
}

wav_header WavManager::getHeader() {
	return header;
}

string WavManager::getName() {
    return filename;
}

void WavManager::readFile(string path) {
    ifstream file(path, ios::binary | ios::in);
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
				soundData[0].push_back((float)buffer[i] / maxSize); //second arg in power is max value of the bitrate
			}
		} else {
			soundData.push_back({});
			for(int i = 0; i < upperBound; i++){
				if(i % 2 == 0) {
					soundData[0].push_back((float)buffer[i] / maxSize); //left ear bit 1
				} else {
					soundData[1].push_back((float)buffer[i] / maxSize); //right ear bit 1
				}
			}
		}
		file.close();
	}
	delete[] buffer;
}

void WavManager::writeToFile(WavManager wave, string filename) {
	vector<vector<float>> soundData = wave.getData();
	wav_header header = wave.getHeader();

	ofstream fileOutput(filename, ios::binary | ios::out);
	fileOutput.write((char*)&header, sizeof(header));

	int maxSize = pow(2, header.bits_per_sample - 1);

	if (header.num_channels == 1) {
		for (int i = 0; i < soundData[0].size(); i++) {
			short number = soundData[0].at(i) * maxSize;
			fileOutput.write((char*)&number, 2);
		}
	} else {
		for (int i = 0; i < soundData[1].size(); i++) {
			short number = soundData[0].at(i) * maxSize;
			fileOutput.write((char*)&number, 2);
			number = soundData[1].at(i) * maxSize;
			fileOutput.write((char*)&number, 2);
		}
	}

	fileOutput.close();
}