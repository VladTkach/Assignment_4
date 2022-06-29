#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#define MINUS 128
using namespace std;

class Writer {
public:
    static void writeName(string &name, ofstream &outFile);

    static void writeElements(queue<char> &elements, ofstream &outFile);
};
