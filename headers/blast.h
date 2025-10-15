#ifndef BLAST_H
#define BLAST_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <vector>
using namespace std;

// structure pr stocker les informarions intéressante du fichier pin
struct dataPin {
    int numberOfprot;
    vector<uint32_t> header_offsets;
    vector<uint32_t> sequence_offsets;
};

inline uint32_t swap(uint32_t val);
dataPin read_pin(const string& pin_path);

#endif