#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "WaveFileManager.h"

class Model {
    private:
        WavReader * wr;
    public:
        void openFile(std::string fileName);
};


#endif