#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Reader {
public:
    static string getName(ifstream &inFile, int &start);
};

