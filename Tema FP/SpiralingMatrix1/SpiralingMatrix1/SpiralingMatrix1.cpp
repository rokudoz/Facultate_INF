#include <iostream>

using namespace std;

int main()
{
	int matrice[5][5] = { { 00,01,02,03,04},
						  { 10,11,12,13,14},
						  { 20,21,22,23,24},
						  { 30,31,32,33,34},
						  { 40,41,42,43,44}
	};

	int endOfLines = 0;
	int endOfCollumns = 0;
	int beginningOfLines = 0;
	int beginningOfCollumns = 0;
	int numberOfTotalItems = 0;
	bool doneSpiraling = false;
	int sens = 1;

	/*for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 4; j++)
		{
			cout << "A[" << i << "][" << j << "]= ";
			cin >> matrice[i][j];
			cout << " ";
		}
		cout << endl;
		}*/


	numberOfTotalItems = sizeof(matrice) / sizeof(matrice[0][0]);
	endOfCollumns = sizeof(matrice) / sizeof(matrice[0]);
	endOfLines = sizeof(matrice[0]) / sizeof(matrice[0][0]);

	int column = 0;
	int line = 0;


	while (!doneSpiraling)
	{
		if (sens == 1)
		{
			line = beginningOfCollumns;
			for (size_t i = beginningOfCollumns; i < endOfCollumns; i++)
			{
				cout << matrice[line][column] << " ";
				numberOfTotalItems--;
				column++;
			}

			beginningOfLines++;
			line++;
			if (numberOfTotalItems <= 0)
				doneSpiraling = true;
		}
		if (sens == 2)
		{
			column = endOfCollumns - 1;
			for (size_t i = beginningOfLines; i < endOfLines; i++)
			{
				cout << matrice[line][column] << " ";
				numberOfTotalItems--;
				line++;
			}

			endOfCollumns--;
			column--;
			if (numberOfTotalItems <= 0)
				doneSpiraling = true;
		}
		if (sens == 3)
		{
			line = endOfCollumns;
			for (size_t i = endOfCollumns; i > beginningOfCollumns; i--)
			{
				cout << matrice[line][column] << " ";
				column--;
				numberOfTotalItems--;
			}
			line--;
			endOfLines--;
			if (numberOfTotalItems <= 0)
				doneSpiraling = true;
		}
		if (sens == 4)
		{
			column = beginningOfCollumns;
			for (size_t i = endOfLines; i > beginningOfLines; i--)
			{
				cout << matrice[line][column] << " ";
				line--;
				numberOfTotalItems--;
			}
			column++;
			beginningOfCollumns++;
			if (numberOfTotalItems <= 0)
				doneSpiraling = true;
		}
		sens++;
		if (sens == 5)
			sens = 1;
		cout << " NUMBER OF TOTAL ITEMS " << numberOfTotalItems << endl;
	}
}
