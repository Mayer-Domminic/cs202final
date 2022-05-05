#ifndef CONSOLE_H
#define CONSOLE_H

#include <vector>
#include <string>

using namespace std;

class Console {
private:

public:
    string getFileName();
    vector<string> getProcessList(); 
    string getOutputFileName();
};


#endif