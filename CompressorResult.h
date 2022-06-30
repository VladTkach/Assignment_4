#pragma once

#include <iostream>
#include "FileCompressor.h"

using namespace std;

class CompressorResult {
public:
    static void CompressFileResult(string &name, ofstream &outFile);
};
