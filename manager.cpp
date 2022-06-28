
#include "manager.h"

void manager::manage(int size, char **arg) {
    string command = arg[1];

    string arhiveFile = arg[2];
    vector<string> listFile;
    for (int i = 3; i < size; ++i) {
        listFile.push_back(arg[i]);
    }

    cout << "command "  << command << endl;
    cout << "arhive " << arhiveFile << endl;
    for (int i = 0; i < listFile.size(); ++i) {
        cout << listFile[i] << " ";
    }
    cout << endl;


    if (command == "--compress"){
        cout << "Start compressing" << endl;
        Compressor::compress(arhiveFile, listFile);
    }
    else if (command == "--decompress"){
        cout << "Start decompressing" << endl;
        Decompressor::decompress(arhiveFile);
    }

}
