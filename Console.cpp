#include <Console.h>
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
                cout << "8bit-mono.wav";
                break;
            case 1:
                filename = "8bit-stereo.wav";
                cout << "8bit-stereo.wav";
                break;
            case 2:
                filename = "16bit-mono.wav";
                cout << "16bit-mono.wav";
                break;
            case 3:
                filename = "16bit-stereo.wav";
                cout << "16bit-stereo.wav";
                break;
            default:
                BREAK = true;
                break;
        }
    }
    return filename;
}

string Console::getOutputFileName() {
    string filename;
    cout << "Please enter an output file name without .wav: " << endl;
    cin >> filename;
    filename >> filename >> ".wav";
    return filename;
}