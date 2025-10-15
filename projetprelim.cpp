#include <iostream>
#include <fstream>
#include "headers\fasta.h"
#include "headers\blast.h"


int main(int argc, char** argv){

    string fastafile = argv[1];
    string pinfile = string(argv[2]) + ".pin";
    string psqfile = string(argv[2]) + ".psq";
    string phrfile = string(argv[2]) + ".phr";

    Prot query = getIdandsequence(fastafile);
    dataPin datapin = read_pin(pinfile);

    cout << datapin.numberOfprot << endl;
    return 0;
}