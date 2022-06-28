#include "Compressor.h"

void Compressor::compress(string &name, vector<string> &files) {
    ofstream outFile(name, ios::binary);
    for (int j = 0; j < files.size(); ++j) {
        cout << files[j] << endl;
        writeName(files[j], outFile);
        ifstream inFile(files[j], ios::ate | ios::binary);
        char current;
        int fil_size = inFile.tellg();
        cout << fil_size << endl;
        int repeat = 1;
        char next;
        queue<char> help;
        for (int i = 0; i < fil_size; ++i) {
            cout << i << endl;
            inFile.seekg(i);
            inFile.read((char *) &current, sizeof(char));
            next = (char) inFile.peek();
            if (next != current || repeat >= 126) {
                if (repeat == 1) {
                    help.push(current);
                    if(help.size() == 127){
                        writeElements(help, outFile);
                    }
                } else {
                    if (!help.empty()) {
                        writeElements(help, outFile);
                    }
                    outFile.write((char *) &repeat, sizeof(char));
                    outFile.write((char *) &current, sizeof(char));
                }
                repeat = 0;
            }
            repeat++;
        }
        writeElements(help, outFile);
    }
}

void Compressor::writeElements(queue<char> &elements, ofstream &outFile) {
    int temp = elements.size();
    int minus = 128;
    outFile.write((char *) &minus, sizeof(char));
    outFile.write((char *) &temp, sizeof(char));
    while (!elements.empty()) {
        outFile.write((char *) &elements.front(), sizeof(char));
        elements.pop();
    }
}

void Compressor::writeName(string &name, ofstream &outFile) {
    int indicator = 0;
    outFile.write((char *) &indicator, sizeof(char));
    for (int i = 0; i < name.length(); ++i) {
        outFile.write((char *) &name[i], sizeof(char));
    }
    outFile.write((char *) &indicator, sizeof(char));
}