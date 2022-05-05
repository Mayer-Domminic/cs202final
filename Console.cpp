#include "Console.h"
#include <iostream>
#include <string>

using namespace std;

string Console::getFileName() {
    int file;
    string filename;
    bool BREAK = false;
    cout << "~~~Audio wav file Program~~~" << endl;

    while (BREAK != true) {
        cout << "Please select a filename from the list: " << endl;
        cout << "\n - (0) 8bit-mono.wav" << endl;
        cout << " - (1) 8bit-stereo.wav" << endl;
        cout << " - (2) 16bit-mono.wav" << endl;
        cout << " - (3) 16bit-stereo.wav\n" << endl;
        cin >> file;
        cout << "You selected: ";

        //case handling
        switch (file) {
            case 0:
                filename = "8bit-mono.wav";
                cout << "8bit-mono.wav" << endl;
                BREAK = true;
                break;
            case 1:
                filename = "8bit-stereo.wav";
                cout << "8bit-stereo.wav" << endl;
                BREAK = true;
                break;
            case 2:
                filename = "16bit-mono.wav";
                cout << "16bit-mono.wav" << endl;
                BREAK = true;
                break;
            case 3:
                filename = "16bit-stereo.wav";
                cout << "16bit-stereo.wav" << endl;
                BREAK = true;
                break;
            default:
                BREAK = true;
                break;
        }
    }
    return filename;
}


std::vector<std::string> Console::getProcessList() {
    std::vector<std::string> processList;
    bool BREAK = false, e=false, n=false;
    int file;

    std::cout << "What would you like to do to the audio file? " << std::endl;

    while (BREAK != true) {
        std::cout << "\n - (0) Quit" << std::endl;
        std::cout << " - (1) Echo" << std::endl;
        std::cout << " - (2) Normalize" << std::endl;
        std::cin >> file;

        //case handling
        switch (file) {
            case 1:
                if (e!=true) {
                    processList.push_back("Echo");
                    std::cout << "Echo added" << std::endl;
                    e=true;
                }
                break;
            case 2:
                if (n!=true) {
                    processList.push_back("Normalize");
                    std::cout << "Normalize added" << std::endl;
                    n=true;
                }
                break;
            default:
                BREAK = true;
                break;
        }
    }
    return processList; 
}

string Console::getOutputFileName() {
    string filename;
    cout << "Please enter an output file name without .wav: " << endl;
    cin >> filename;
    filename = filename + ".wav";
    return filename;
}