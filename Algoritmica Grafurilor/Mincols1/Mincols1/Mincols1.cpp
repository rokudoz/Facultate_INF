#include <iostream>
#include <stdio.h>

#define NMAX 100

using namespace std;

int main() {
	FILE* fin, * fout;
	int n, i, j;
	int matrix[NMAX][NMAX];
	int elemeteMin[21];
	int elementeSize = 0;
	int produsElem = 1;
	int ultimaCifra = 0;

	fin = fopen("mincols1.in", "r");
	fout = fopen("mincols1.out", "w");

	if (fin != NULL)
	{
		fscanf(fin, "%d", &n);     // citim numarul de linii si coloane

		if (n<2)
		{
			n = 2;
		}
		else if (n>30)
		{
			n = 30;
		}

		// citim elementele
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				fscanf(fin, "%d", &matrix[i][j]);
			}
		}

		//Print elem
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

		j = n - 1;
		for (i = 0; i < n; i++) {
			if (j >= 0)
			{
				int current = matrix[i][j];
				bool min = true;
				for (int k = 0; k < n; k++) {

					if (current > matrix[k][j])
					{
						min = false;
					}
				}
				if (min)
				{
					elemeteMin[elementeSize] = current;
					elementeSize++;
				}

				j--;
			}
		}

		cout << "\nElem min ";
		for (i = 0; i < elementeSize; i++) {
			cout << elemeteMin[i] << " ";
			produsElem *= elemeteMin[i];
		}
		cout << "\nProdus elem " << produsElem << endl;

		ultimaCifra = produsElem % 10;

		cout << "ultima cifra " << ultimaCifra;
		fprintf(fout, "%d ", ultimaCifra);
		getchar();
	}
	else {
		cout << "matrice.in not existent";
		getchar();
	}
	return 0;
}