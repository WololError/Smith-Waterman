#include "../headers/fasta.h"
//fonction qui lit une fichier fasta qui ne contient qu'un seul prot et qui renvoie une objet de la structure Prot
//qui servira à la représenter
Prot getIdandsequence(const string& filefasta){
    ifstream fichier(filefasta);
    
    if (!fichier.good()) {
        std::cerr << "fichier non ouvert" << std::endl;
        return {"",""};
    }

    string ligne, id, sequence;
    while(getline(fichier, ligne)){
        
        if (ligne[0] == '>'){
            id = ligne.erase(0,1);  // on récupère l'id
        }
        
        else{
            sequence += ligne;     // on actualise le sequence car elle prend plusieurs lignes
        }
    }
    fichier.close();
    Prot query;
    query.id = id;
    query.sequence = sequence;
    cout << sequence << endl;
    return query;
}