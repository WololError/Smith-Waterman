#ifndef BLAST_H
#define BLAST_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <vector>
#include <map>
using namespace std;

// structure pr stocker les informarions intéressante du fichier pin
struct dataPin {
    int numberOfprot;
    vector<uint32_t> header_offsets;
    vector<uint32_t> sequence_offsets;
};

uint32_t swapbytes(uint32_t val);
dataPin read_pin(const string& pin_path);
string read_sequence(ifstream& file, const int a,const int b);
string read_header(ifstream& file, const int a, const int b);

#endif