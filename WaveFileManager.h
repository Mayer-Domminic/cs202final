#ifndef WAVEFILEMANAGER_H
#define WAVEFILEMANAGER_H

#include <iostream>

class WaveFileManager {
    private:
    public:
        void read(const std::string &fileName);
        void WaveFileManager::read8bit(const std::string &fileName);
        void WaveFileManager::save(const std::string &outputFileName);
        const std::vector<float> &WaveFileManager::getData();
        void WaveFileManager::updateSoundData(std::vector<float> newData);
}

#endif