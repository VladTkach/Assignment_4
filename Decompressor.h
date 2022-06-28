#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Decompressor {
public:
    static void decompress(string &name);

    static void decompressFile(ifstream &inFile, string &fileName, int &start, int file_size);

    static string getName(ifstream &inFile, int &start);
};

