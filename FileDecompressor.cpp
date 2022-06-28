#include "FileDecompressor.h"

void FileDecompressor::decompressFile(ifstream &inFile, string &fileName, int &start, int file_size) {
    ofstream outFile(fileName, ios::binary);
    char repeat;
    char current;
    for (int i = start; i < file_size; ++i) {
        inFile.seekg(i);
        inFile.read((char *) &repeat, sizeof(char));
        if (repeat == 0) {
            start = i;
            break;
        }
        else if (repeat == -128) {
            inFile.read((char *) &repeat, sizeof(char));
            for (int j = 0; j < repeat; ++j) {
                inFile.read((char *) &current, sizeof(char));
                outFile.write((char *) &current, sizeof(char));
            }
            i += (int) (repeat) + 1;
        } else {
            inFile.read((char *) &current, sizeof(char));
            for (int j = 0; j < int(repeat); ++j) {
                outFile.write((char *) &current, sizeof(char));
            }
            i++;
        }
    }
    outFile.close();
}
