#include "../headers/Protein.h"
#include "../headers/blast.h"

vector<Protein> Protein::initProtlist(const string& phrfile, const string& psqfile, const dataPin pin){
    
    ifstream phr(phrfile, ios::binary);
    if (!phr) throw runtime_error("Impossible d'ouvrir le fichier .phr");

    ifstream psq(psqfile, ios::binary);
    if (!psq) throw runtime_error("Impossible d'ouvrir le fichier .phr");

    vector<Protein> proteins(pin.numberOfprot);

    for(int i = 0; i < pin.sequence_offsets.size() - 1 ; i++){
        string p  = read_header(phr, pin.header_offsets[i],pin.header_offsets[i + 1]);
        string seq = read_sequence(psq, pin.sequence_offsets[i], pin.sequence_offsets[i + 1]);
        proteins[i].id = p;
        proteins[i].sequence = seq;
    }

    phr.close();
    psq.close();
    return proteins;
}

string Protein::getseq(){
    return this->sequence;
}

string Protein::getid(){
    return this->id;
}