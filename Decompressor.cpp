#include "Decompressor.h"

void Decompressor::decompress(string &name) {
    ifstream inFile(name, ios::ate | ios::binary);
    int file_size = (int)inFile.tellg();

    int start = 1;
    char current;
    string new_name;

    inFile.seekg(0);
    inFile.read((char *) &current, sizeof(char));

    while (start != file_size){
        new_name = Reader::getName(inFile, start);
        FileDecompressor::decompressFile(inFile, new_name, start, file_size);
        start = (int)inFile.tellg();
    }
    inFile.close();
}



