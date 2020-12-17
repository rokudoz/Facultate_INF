#include <iostream>

#define NMAX 1000

using namespace std;

int main() {
	FILE* fin, * fout;
	int n, i, j;
	int matrix[NMAX][NMAX];

	fin = fopen("matrice.in", "r");
	fout = fopen("matrice.out", "w");

	if (fin != NULL)
	{
		fscanf(fin, "%d", &n);     // citim numarul de linii si coloane

	// citim elementele primei matrice
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				fscanf(fin, "%d", &matrix[i][j]);
			}
		}

		cout << "N= " << n << endl;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		getchar();
	}
	else {
		cout << "matrice.in not existent";
		getchar();
	}
		
	return 0;
}