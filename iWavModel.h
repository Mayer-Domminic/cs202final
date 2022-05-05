#ifndef FEED_BACK_ECHO_IWAVEMODEL_H
#define FEED_BACK_ECHO_IWAVEMODEL_H

#include "WavManager.h"

#include <vector>
#include <string>
using namespace std;

class iWavModel {
private:
	WavManager wave;
public:
	void readFile(string newFile);
	void writeFile(string outFile);
	void setData(vector<vector<float>> newData);
	vector<vector<float>> getData();
	string getAttributes();
};

#endif //FEED_BACK_ECHO_IWAVEMODEL_H