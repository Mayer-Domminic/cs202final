#include "iWavModel.h"
#include "WavManager.h"
#include "WaveHeader.h"

#include <iostream>
#include <sstream>
using namespace std;

void iWavModel::readFile(string newFile) {
	wave.readFile(newFile);
}

void iWavModel::writeFile(string outFile) {
	wave.writeToFile(wave, outFile);
}

vector<vector<float>> iWavModel::getData() {
	return wave.getData();
}

void iWavModel::setData(vector<vector<float>> newData) {
	wave.setData(newData);
}

string iWavModel::getAttributes() {
	stringstream attributes;
	string name = wave.getName();

	attributes << "File Name: " + name << endl;
	attributes << "Sample Rate: " + to_string(wave.getHeader().sample_rate) << endl;
	attributes << "Bits per Sample: " + to_string(wave.getHeader().bits_per_sample) << endl;

	if (wave.getHeader().num_channels == 1) {
		attributes << "Format: Mono " << endl;
	} else {
		attributes << "Format: Stereo " << endl;
	}

	wav_header header = wave.getHeader();
	float len = ((float)header.data_bytes) / ((header.sample_rate * header.num_channels * header.bits_per_sample) / 8);

	if (len > 60) {
		len = len / 60;
		attributes << "Audio Length (mins): " + to_string(len) << endl;
	} else {
		attributes << "Audio Length (secs): " + to_string(len) << endl;
	}

	return attributes.str();	
}