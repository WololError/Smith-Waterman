all: projet
projetprelim: projetprelim.cpp
	g++ projetprelim.cpp src/fasta.cpp src/blast.cpp -o  projetprelim
	./projetprelim query/P00533.fasta database/uniprot_sprot.fasta
projet:
	@echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
projetopt:
	@echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
cleanl: 
	rm *.o
cleanw:
	del /Q *.o
