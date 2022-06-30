
#include "CompressorResult.h"

void CompressorResult::CompressFileResult(string &name, ofstream &outFile) {
    if (FileCompressor::compressFile(name, outFile)){
        cout << "Done" << endl;
    }
    else
        cout << "Fail" << endl;
}
