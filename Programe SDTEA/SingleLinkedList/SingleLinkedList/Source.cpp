#include <iostream>

using namespace std;


struct Nod
{
	int numar;      //Memorarea efectiva a numarului
	Nod* urmator;   //Memorarea legaturii catre urmatorul nod
	Nod* precedent;
};
Nod* cap = NULL;    //Declararea listei vida

// Prototip functii
void afisareLista(Nod* cap);
void inserareLaInceput(Nod*& cap, int valoare);
void inserareFinal(Nod*& cap, int valoare);


// Main
void main() {
	for (size_t i = 0; i < 10; i++)
	{
		inserareFinal(cap, i);
	}
	afisareLista(cap);
}

void afisareLista(Nod* cap) {
	while (cap != NULL)
	{
		cout << cap->numar << "\n";	// Afisam numarul stocat 
		cap = cap->urmator;	// Mutam elementul curent la urmatorul element din lista
	}
}

void inserareLaInceput(Nod*& cap, int valoare) {
	Nod* newNod = new Nod;	//Creeam noul nod si ii atribuim valoarea din paramentru
	newNod->precedent = NULL;
	newNod->numar = valoare;
	newNod->urmator = cap;	//Mutam sageata catre primul element din lista

	if (cap != NULL){
		cap->precedent = newNod;
	}
	cap = newNod;	//Inlocuim primul element din lista
}

void inserareFinal(Nod*& cap, int valoare)
{
	//Creeam noul nod si ii atribuim valoarea din paramentru
	Nod* elem_final = new Nod;
	elem_final->numar = valoare;
	elem_final->urmator = NULL;
	elem_final->precedent = NULL;
	if (cap == NULL) // In cazul in care lista noastra este vida, punem elementul in lista
		cap = elem_final;
	else
	{
		//Parcurgem lista pana la final
		Nod* nod_curent = cap;
		while (nod_curent->urmator != NULL)
			nod_curent = nod_curent->urmator;
		//Mutam sageata ultimului element catre elementul creat anterior
		nod_curent->urmator = elem_final;
		elem_final->precedent = nod_curent;
	}
}