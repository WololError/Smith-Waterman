#ifndef BLOSUM_H
#define BLOSUM_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Blosum {

private:
    vector<vector<int>> matrix;
    map<char, int> indexMap;
    int size;

    int parseBlosumSize(const string& blosumfile) const;
    map<char, int> parseIndexMap(const string& blosumfile) const;
;
public:
    Blosum(const string& blosumfile);
    int Score(char acide1, char acide2) const;
    void printMatrix() const;
};

vector<int> linetovector(string& line, int number);

#endif
