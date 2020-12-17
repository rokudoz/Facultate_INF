#include <iostream>

using namespace std;

struct nod {
	int info;
	nod* urm;
};

void afisareLista(nod* cap) {
	while (cap != NULL)
	{
		cout << cap->info << endl;
		cap = cap->urm;
	}
}

void inserareInceput(nod*& cap, int info) {
	nod* newNod = new nod;
	newNod->info = info;
	newNod->urm = cap;
	cap = newNod;
}

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

void sterge(nod*& p, nod* q);
void sterge(nod*& p, nod* q)
{
	if (q == p)
	{
		p = p->urm;
		return;
	}
	nod* cap = p;
	while (cap->urm != q)
		cap = cap->urm;
	if (q == NULL)cap->urm = NULL;
	else cap->urm = q->urm;
}

int main()
{
	nod* cap = NULL;

	inserareInceput(cap, 4);
	inserareInceput(cap, 3);
	inserareInceput(cap, 2);
	inserareInceput(cap, 1);

	afisareLista(cap);

	return 0;
}