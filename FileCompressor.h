#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include "Writer.h"
#define LIMIT 127

using namespace std;
class FileCompressor {
public:
    static void compressFile(string &name, ofstream &outFile);
};

