#include "Compressor.h"

void Compressor::compress(string &name, vector<string> &files) {
    ofstream outFile(name, ios::binary);
    for (int j = 0; j < files.size(); ++j) {
        Writer::writeName(files[j], outFile);
        FileCompressor::compressFile(files[j], outFile);
    }
}