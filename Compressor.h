#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include "FileCompressor.h"
#include "Writer.h"

using namespace std;

class Compressor {
    static void writeElements(queue<char> &elements, ofstream &outFile);

    static void writeName(string &name, ofstream &outFile);

    static void compressFile(string &name, ofstream &outFile);
public:
    static void compress(string &name, vector<string> &files);

};


