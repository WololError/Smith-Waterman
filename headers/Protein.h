#include <string>
#include <vector>
#include "blast.h"
using namespace std;

class Protein{

private:
    string id;
    string sequence;
    int sw_score = 0;

public:
    static vector<Protein> initProtlist(const string& phrfile, const string& psqfile, const dataPin pin);
    string getseq();
    string getid();
};

