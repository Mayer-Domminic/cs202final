#ifndef FEED_BACK_ECHO_IWAVEMODEL_H
#define FEED_BACK_ECHO_IWAVEMODEL_H

#include "FileAttributes.h"
#include "Console.h"
#include <vector>
#include <string>
using namespace std;

class iWavModel {
private:
	FileAttributes attr;
	string outputFilename = console -> getOutputFileName();
public:
	/*
	virtual FileAttributes openFile(const std::string &file_name)=0;
	virtual vector<string> getProcessList()=0;
	virtual void setOutPutFileName(const std::string& outputFileName)=0;
	virtual void processFile(const std::string& processID)=0;
	*/

	FileAttributes openFile(const string &filename)=0;
};

#endif //FEED_BACK_ECHO_IWAVEMODEL_H