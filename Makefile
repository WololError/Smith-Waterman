all: projet
projetprelim: projetprelim.cpp
	g++ -o prog projetprelim.cpp
	./prog query\P00533.fasta
projet:
	@echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
projetopt:
	@echo "Modifiez le fichier Makefile pour permettre la compilation de votre projet"
cleanl: 
	rm *.o
cleanw:
	    del /Q *.o
