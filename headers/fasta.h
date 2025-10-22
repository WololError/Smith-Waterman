#ifndef FASTA_H
#define FASTA_H

#include <iostream>
#include <fstream>
using namespace std;
//structure qui représente une protein
struct Prot {
    string id;
    string sequence; //on stocke le séquence ds un string pr l'instant, reste à voir quelle structure sera intéressante pr l'algoritme de Smith-Waterman
};

Prot getIdandsequence(const string& files);

#endif