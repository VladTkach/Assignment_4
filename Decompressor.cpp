#include "Decompressor.h"

void Decompressor::decompress(string &name) {
    ifstream inFile(name, ios::ate | ios::binary);
    int file_size = inFile.tellg();
    cout << file_size << endl;
    inFile.seekg(0);
    char current;
    inFile.read((char *) &current, sizeof(char));
    cout << "c-" << (int) current << endl;
    int start = 1;
    string new_name;

    while (start != file_size){
        new_name = getName(inFile, start);
        cout << new_name << " " << start << endl;
        decompressFile(inFile, new_name, start, file_size);
        start = inFile.tellg();
    }
    inFile.close();
}

string Decompressor::getName(ifstream &inFile, int &start) {
    string name;
    char current;
    do {
        inFile.read((char *) &current, sizeof(char));
        name += current;
    } while (current != 0);
    start += name.length();
    name.erase(name.length() - 1);
    return name;
}

void Decompressor::decompressFile(ifstream &inFile, string &fileName, int &start, int file_size) {
    ofstream outFile(fileName, ios::binary);
    char repeat;
    char current;
    for (int i = start; i < file_size; ++i) {
        inFile.seekg(i);
        inFile.read((char *) &repeat, sizeof(char));
        cout << "repeat" << (int) repeat << endl;
        if (repeat == 0) {
            cout << "stop";
            start = i;
            cout << "start - " << start << endl;
            break;
        }
        if (repeat == -128) {
            inFile.read((char *) &repeat, sizeof(char));
            for (int j = 0; j < repeat; ++j) {
                inFile.read((char *) &current, sizeof(char));
                outFile.write((char *) &current, sizeof(char));
            }
            i += (int) (repeat) + 1;
        } else {
            inFile.read((char *) &current, sizeof(char));
            for (int j = 0; j < int(repeat); ++j) {
                outFile.write((char *) &current, sizeof(char));
            }
            i++;
        }
    }
    outFile.close();
}


