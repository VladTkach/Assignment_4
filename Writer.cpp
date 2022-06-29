#include "Writer.h"

void Writer::writeName(string &name, ofstream &outFile) {
    int indicator = 0;
    outFile.write((char *) &indicator, sizeof(char));
    for (int i = 0; i < name.length(); ++i) {
        outFile.write((char *) &name[i], sizeof(char));
    }
    outFile.write((char *) &indicator, sizeof(char));
}

void Writer::writeElements(queue<char> &elements, ofstream &outFile) {
    int temp = (int) elements.size();
    int minus = MINUS;
    outFile.write((char *) &minus, sizeof(char));
    outFile.write((char *) &temp, sizeof(char));
    while (!elements.empty()) {
        outFile.write((char *) &elements.front(), sizeof(char));
        elements.pop();
    }
}
