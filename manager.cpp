
#include "manager.h"

void manager::manage(int size, char **arg) {
    string command = arg[1];

    string arhiveFile = arg[2];
    vector<string> listFile;
    for (int i = 3; i < size; ++i) {
        listFile.push_back(arg[i]);
    }

    if (command == "--compress"){
        cout << "Start compressing" << endl;
        Compressor::compress(arhiveFile, listFile);
    }
    else if (command == "--decompress"){
        cout << "Start decompressing" << endl;
        Decompressor::decompress(arhiveFile);
    }
    else{
        cout << "wrong flag!";
    }

}
