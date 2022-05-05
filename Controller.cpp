#include "Controller.h"
#include <vector>
//#include "FileAttributes.h"

bool Controller::run() {
    //user input file name
    std::string fileName = console->getFileName();
    model.readFile(fileName);
    std::vector<std::string> processList = console->getProcessList();
    string attr = model.getAttributes();
    cout << attr << endl;

    return false;
}

void Controller::setConsole(Console *userConsole) {
    console = userConsole;
}