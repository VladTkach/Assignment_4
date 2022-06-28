#include "Decompressor.h"

void Decompressor::decompress(string &name) {
    ifstream inFile(name, ios::ate | ios::binary);
    int file_size = (int)inFile.tellg();

    int start = 1;
    string new_name;
    int sum = 0;
    inFile.seekg(1);
    while (start != file_size){
        new_name = Reader::getName(inFile, start);
        cout << "Getting out file" << new_name << "...";
        FileDecompressor::decompressFile(inFile, new_name, start, file_size);
        cout << " Done" << endl;
        start = (int)inFile.tellg();
        sum++;
    }
    inFile.close();
    cout << sum << " files written";
}



