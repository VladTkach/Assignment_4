
#include "Reader.h"

string Reader::getName(ifstream &inFile, int &start) {
    string name;
    char current;
    do {
        inFile.read((char *) &current, sizeof(char));
        name += current;
    } while (current != 0);
    start += (int)name.length();
    name.erase(name.length() - 1);
    return name;
}
