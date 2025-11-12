#ifndef FASTA_H
#define FASTA_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//structure qui représente une protéine
struct query {
    string id;
    string sequence; //on stocke le séquence ds un string pr l'instant, reste à voir quelle structure sera intéressante pr l'algoritme de Smith-Waterman
};

query getIdandsequence(const string& files);
#endif