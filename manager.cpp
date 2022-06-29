
#include "manager.h"

void manager::manage(int size, char **arg) {
    string command = arg[1];
    string archiveFile = arg[2];

    if (command == "--compress"){
        cout << "Start compressing" << endl;
        vector<string> listFile;
        for (int i = 3; i < size; ++i) {
            listFile.push_back(arg[i]);
        }
        Compressor::compress(archiveFile, listFile);
    }
    else if (command == "--decompress"){
        cout << "Start decompressing" << endl;
        Decompressor::decompress(archiveFile);
    }
    else{
        cout << "wrong flag!";
    }
}
