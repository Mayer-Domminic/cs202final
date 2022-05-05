#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <vector>

using namespace std;

class Processor{
	public:
		vector<float> echo(const vector<float> input, float gain, int delay, int decay);
        vector<float> norm(vector<float> data);
};

#endif