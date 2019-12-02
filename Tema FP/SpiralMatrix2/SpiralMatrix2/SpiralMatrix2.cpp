#include <iostream>

using namespace std;


void main() {

	int matrix[5][5] = { {00,01,02,03,04},
						 {10,11,12,13,14},
						 {20,21,22,23,24},
						 {30,31,32,33,34},
						 {40,41,42,43,44}
	};
	bool done = false;
	int columnMax = 0, columnMin = 0, lineMin = 0, lineMax = 0, arraySize = 0;

	lineMax = sizeof(matrix) / sizeof(matrix[0]);
	columnMax = sizeof(matrix[0]) / sizeof(matrix[0][0]);
	arraySize = sizeof(matrix) / sizeof(matrix[0][0]);
	
	while (!done)
	{
		for (size_t i = columnMin; i < columnMax; i++) {
			cout << matrix[lineMin][i] << " ";
			arraySize--;
		}
		for (size_t i = lineMin + 1; i < lineMax; i++) {
			cout << matrix[i][columnMax - 1] << " ";
			arraySize--;
		}
		for (size_t i = columnMax - 2; i > columnMin; i--)
		{
			cout << matrix[lineMax - 1][i] << " ";
			arraySize--;
		}
		for (size_t i = lineMax - 1; i > lineMin; i--)
		{
			cout << matrix[i][columnMin] << " ";
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