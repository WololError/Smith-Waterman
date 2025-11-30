#ifndef PROTEIN_H
#define PROTEIN_H

#include <string>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>

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
    int getscore() const;
    
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

    static void printbetter(vector<Protein>& v);

    static void computeSW(int start, int end, const query& query, const Blosum& blosum, const string& phrfile, const string& psqfile, const dataPin& pin, int GEP, int GOP, priority_queue<Protein>& thread_results);
    static vector<Protein> createVector(const string& phrfile, const string& psqfile, const dataPin& pin, const query& query, const Blosum& blosum, int GEP, int GOP);

    static void computeSWFromMemory(int start, int end, const query& query, const Blosum& blosum, const vector<char>& phr_data, const vector<char>& psq_data, const dataPin& pin, int GEP, int GOP, priority_queue<Protein>& thread_results);
    static vector<Protein> createVectorFromMemory(string& phr, string& psq, const dataPin& pin, const query& query, const Blosum& blosum, int GEP, int GOP);
    
};

#endif