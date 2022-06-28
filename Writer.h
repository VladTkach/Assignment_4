#pragma once

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class Writer {
public:
    static void writeName(string &name, ofstream &outFile);

    static void writeElements(queue<char> &elements, ofstream &outFile);
};
