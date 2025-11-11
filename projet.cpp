#include <iostream>
#include <fstream>
#include <chrono>

#include "headers/fasta.h"
#include "headers/blast.h"
#include "headers/blosum.h"

int main(int argc, char** argv){

    string fastafile = argv[1];
    string pinfile = string(argv[2]) + ".pin";
    string psqfile = string(argv[2]) + ".psq";
    string phrfile = string(argv[2]) + ".phr";
    string blosumfile = string(argv[3]);

    int GOP = atoi(argv[4]); // GOP = Gap Open Penalty
    int GEP = atoi(argv[5]); // GEP = Gap Extension Penalty

    Prot query = getIdandsequence(fastafile);
    dataPin pindata = read_pin(pinfile);
    Blosum scoring(blosumfile);

    //scoring.printMatrix();
    cout << scoring.Score('K', 'B') << endl;
    cout << scoring.Score('W', 'W') << endl;
    cout << scoring.Score('Z', 'T') << endl;
    return 0;
}