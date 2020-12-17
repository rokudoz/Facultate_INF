#include <iostream>

using namespace std;

struct nod {
	int info;
	nod* urm;
};

int numarare(nod* p);
int numarare(nod* p) {
	int counter = 1;
	nod* pe = p;

	while (pe->urm != NULL)
	{
		pe = pe->urm;
		counter++;
	}
	return counter;
}

