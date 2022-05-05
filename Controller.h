#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Console.h"

class Controller {
    private:
        Console *console;
        iWavModel *model;
    public:
        bool run();
        void setConsole(Console *console);
};


#endif