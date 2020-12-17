#include <iostream>

using namespace std;

struct nod {
	int info;
	nod* urm;
};

void inserare(nod* p, nod* q, int x);

void inserare(nod* p, nod* q, int x) {
	nod* newNod = new nod;
	newNod->info = x;
	newNod->urm = NULL;

	if (p == NULL)
	{
		p = newNod;
		return;
	}

	if (p == q)
	{
		newNod->urm = p;
		p = newNod;
		return;
	}

	newNod->urm = q->urm;
	q->urm = newNod;
}
