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

    query query = getIdandsequence(fastafile);
    dataPin pindata = read_pin(pinfile);

    //CREATION DU VECTOR DE PROT
    auto start = std::chrono::high_resolution_clock::now();

    vector<Protein> proteins = Protein::initProtlist(phrfile, psqfile, pindata); 

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "vector crée en : " << elapsed.count() << " secondes\n";


    //RECHERCHE DU QUERY DS LE VECTOR DE PROT
    auto startp = std::chrono::high_resolution_clock::now(); 

    findquery(query, proteins);

    auto endp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedp = endp - startp;
    std::cout << "protein trouvé en : " << elapsedp.count() << " secondes\n";
    return 0;
}