#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include "FileCompressor.h"
#include "Writer.h"

using namespace std;

class Compressor {
public:
    static void compress(string &name, vector<string> &files);

};


