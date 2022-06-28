#pragma once

#include <iostream>
#include <fstream>
#include "Reader.h"
#include "FileDecompressor.h"

using namespace std;

class Decompressor {
public:
    static void decompress(string &name);
};

