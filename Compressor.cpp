#include "Compressor.h"

void Compressor::compress(string &name, vector<string> &files) {
    ofstream outFile(name, ios::binary);
    for (int j = 0; j < files.size(); ++j) {
        cout << "Compressing file " << files[j] << "... ";
        CompressorResult::CompressFileResult(files[j], outFile);
    }
    cout << "Result written to" << name;
}