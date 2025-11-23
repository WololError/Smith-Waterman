#ifndef PROTEIN_H
#define PROTEIN_H

#include <string>
#include <vector>
#include <queue>

#include "blast.h"
#include "blosum.h"

struct query;


using namespace std;

class Protein{

private:
    string id;
    string sequence;
    int sw_score = 0;
    
public:
    static vector<Protein> initProtlist(const string& phrfile, const string& psqfile, const dataPin pin);
    string getseq() const;
    string getid() const;
    
    bool operator< (const Protein &other) const {
        return sw_score < other.sw_score;
    }

    bool operator> (const Protein &other) const {
        return sw_score > other.sw_score;
    }

    bool operator== (const Protein &other) const {
        return sw_score == other.sw_score;
    }
    
    static priority_queue<Protein> initProtqueue(const query& q, Blosum& blosum, string& phrfile, const string& psqfile, const dataPin& pin, int GEP, int GOP);
    static void print20best(priority_queue<Protein>& pq);
};

#endif