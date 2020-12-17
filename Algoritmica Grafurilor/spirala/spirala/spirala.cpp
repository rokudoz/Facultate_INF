#include <iostream>
#include <stdio.h>

#define MAX_VAL 1000

using namespace std;


int main() {
	FILE* fin, * fout;
	int arrSize;
	int matrix[23][23];


	fin = fopen("spirala.in", "r");
	fout = fopen("spirala.out", "w");

	fscanf(fin, "%d", &arrSize);
	if (fin != NULL)
	{
		if (arrSize > 1 && arrSize < 24)
		{
			for (int i = 0; i < arrSize; i++)
			{
				for (int j = 0; j < arrSize; j++) {
					fscanf(fin, "%d", &matrix[i][j]);
					if (matrix[i][j] > MAX_VAL)
					{
						matrix[i][j] = MAX_VAL;
					}
				}
			}

			bool done = false;
			int columnMax = 0, columnMin = 0, lineMin = 0, lineMax = 0, arraySize = 0;

			lineMax = arrSize;
			columnMax = arrSize;
			arraySize = arrSize * arrSize;

			while (!done)
			{
				for (size_t i = columnMin; i < columnMax; i++) {
					cout << matrix[lineMin][i] << " ";
					fprintf(fout, "%d ", matrix[lineMin][i]);
					arraySize--;
				}
				for (size_t i = lineMin + 1; i < lineMax; i++) {
					cout << matrix[i][columnMax - 1] << " ";
					fprintf(fout, "%d ", matrix[i][columnMax - 1]);
					arraySize--;
				}
				for (size_t i = columnMax - 2; i > columnMin; i--)
				{
					cout << matrix[lineMax - 1][i] << " ";
					fprintf(fout, "%d ", matrix[lineMax - 1][i]);
					arraySize--;
				}
				for (size_t i = lineMax - 1; i > lineMin; i--)
				{
					cout << matrix[i][columnMin] << " ";
					fprintf(fout, "%d ", matrix[i][columnMin]);
					arraySize--;
				}
				columnMin++;
				columnMax--;
				lineMin++;
				lineMax--;
				if (arraySize <= 0)
				{
					done = true;
				}
			}
		}
		else
		{
			cout << "N is not within limits ";
		}
	}
	else {
		cout << "Input file not found " << endl;
	}

	return 0;
}