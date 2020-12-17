#include <iostream>

using namespace std;

struct nod {
	int info;
	nod* urm;
};

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

