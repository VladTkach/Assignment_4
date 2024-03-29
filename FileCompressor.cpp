#include "FileCompressor.h"

bool FileCompressor::compressFile(string &name, ofstream &outFile) {
    ifstream inFile(name, ios::ate | ios::binary);
    if (!inFile.is_open()){
        return false;
    }
    Writer::writeName(name, outFile);
    int fil_size = (int)inFile.tellg();

    char next;
    char current;
    int repeat = 1;
    queue<char> help;
    for (int i = 0; i < fil_size; ++i) {
        inFile.seekg(i);
        inFile.read((char *) &current, sizeof(char));
        next = (char) inFile.peek();
        if (next != current || repeat >= LIMIT) {
            if (repeat == 1) {
                help.push(current);
                if(help.size() == LIMIT){
                    Writer::writeElements(help, outFile);
                }
            } else {
                if (!help.empty()) {
                    Writer::writeElements(help, outFile);
                }
                outFile.write((char *) &repeat, sizeof(char));
                outFile.write((char *) &current, sizeof(char));
            }
            repeat = 0;
        }
        repeat++;
    }
    Writer::writeElements(help, outFile);
    return true;
}
