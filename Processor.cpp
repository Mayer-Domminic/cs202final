#include "Processor.h"

#include <cmath>
#include <algorithm>

vector<float> Processor::echo(const vector<float> input, float gain, int delay, int decay) {
    vector<float> output;
    auto decay = log(0.01)/log(gain);
    int new_size = int(input.size() + delay * decay);
    vector<float> extendedInput(new_size, 0.0f);
    extendedInput.insert(extendedInput.begin(), input.begin(), input.end());
    output.reserve(extendedInput.size());
    for (int i = 0; i < new_size; i++) {
        if (i > delay) {
            output.push_back(extendedInput[i] + gain * output[i-delay]);
        } else {
            output.push_back(extendedInput[i]);
        }
    }
    return output;
}

vector<float> Processor::norm(vector<float> soundData) {
    auto maxLocation = max_element(soundData.begin(), soundData.end(),
        [](float a, float b) {
            return abs(a) < abs(b);
        }
    );

    float maxValue = *maxLocation;

    for (int i = 0; i < soundData.size(); i++) {
        soundData[i] = soundData[i] / abs(maxValue);
        //buffer[i] = (short) (soundData[i] = 32768);
    }
    return soundData;
}