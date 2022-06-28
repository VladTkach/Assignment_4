#pragma once

#include <iostream>
#include <fstream>
#include "Reader.h"

using namespace std;
class FileDecompressor {
public:
    static void decompressFile(ifstream &inFile, string &fileName, int &start, int file_size);
};

