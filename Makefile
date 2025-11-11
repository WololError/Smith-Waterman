all: projet
projetprelim: projetprelim.cpp
    g++ projetprelim.cpp src/fasta.cpp src/blast.cpp -o  projetprelim
projet: projet.cpp
    g++ projet.cpp src/fasta.cpp src/blast.cpp src/blosum.cpp -o  projet
    ./projet query/P00533.fasta database/uniprot_sprot.fasta blosum/BLOSUM62 11 1
projetopt:
    @echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
cleanl: 
    rm *.o
cleanw:
    del /Q *.o