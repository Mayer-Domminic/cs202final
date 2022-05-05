#ifndef WAV_H
#define WAV_H

#include "WaveHeader.h"

#include <iostream>
#include <vector>

using namespace std;

class WavManager {
private:
	wav_header header;
    string filename;
	vector<vector<float>> soundData = {{}}; // priv 2d vector
public:
	/*
	virtual FileAttributes openFile(const std::string &file_name)=0;
	virtual vector<string> getProcessList()=0;
	virtual void setOutPutFileName(const std::string& outputFileName)=0;
	virtual void processFile(const std::string& processID)=0;
	*/
	void readFile(string path);
    void setData(vector<vector<float>> newDatav);
    vector<vector<float>> getData();
    wav_header getHeader();
    string getName();
};

#endif //WAV_H