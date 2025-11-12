#include <iostream>
#include <fstream>
#include <chrono>

#include "headers/fasta.h"
#include "headers/blast.h"
#include "headers/Protein.h"

int main(int argc, char** argv){

    string fastafile = argv[1];
    string pinfile = string(argv[2]) + ".pin";
    string psqfile = string(argv[2]) + ".psq";
    string phrfile = string(argv[2]) + ".phr";

    Prot query = getIdandsequence(fastafile);
    dataPin pindata = read_pin(pinfile);
    auto start = std::chrono::high_resolution_clock::now();    
    vector<Protein> proteins = Protein::initProtlist(phrfile, psqfile, pindata); 
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "vector crée en : " << elapsed.count() << " secondes\n";
    auto startp = std::chrono::high_resolution_clock::now(); 
    for(int i = 0; i < proteins.size(); i++){
        //cout << i << endl;
        if (query.sequence == proteins[i].getseq()){
            cout << proteins[i].getid() << endl;
            auto endp = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = endp - startp;
            std::cout << "protein trouvé en : " << elapsed.count() << " secondes\n";
            break;
        }
    }
    return 0;
}