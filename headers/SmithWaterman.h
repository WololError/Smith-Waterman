#ifndef SMITHWATERMAN_H
#define SMITHWATERMAN_H

#include <vector>
#include <algorithm>

#include "fasta.h"
#include "Protein.h"
#include "blosum.h"

using namespace std;

pair<string, string> GetProtGapped(vector<vector<int>>& H, 
	const query& query, const Protein& prot, const Blosum& blosum, int i, int j, int gap_penalty);

int SWmatrix(const query& query, const Protein& prot, const Blosum& blosum, const int gap_open_penalty, const int gap_extension);

#endif