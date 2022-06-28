#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <queue>


using namespace std;

class Compressor {
public:
    static void compress(string &name, vector<string> &files);

    static void writeElements(queue<char> &elements, ofstream &outFile);

    static void writeName(string &name, ofstream &outFile);
};


