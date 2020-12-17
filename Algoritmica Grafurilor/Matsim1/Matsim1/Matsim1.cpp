#include <iostream>

#define MAX_VAL 1000000

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n > 0 && n < 101)
	{

		//Dynamic 2d matrix
		int** initialMatrix = new int* [n];
		for (int i = 0; i < n; ++i)
			initialMatrix[i] = new int[n];

		int** resultMatrix = new int* [n];
		for (int i = 0; i < n; ++i)
			resultMatrix[i] = new int[n];


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				cin >> initialMatrix[i][j];
				if (initialMatrix[i][j] > MAX_VAL)
				{
					initialMatrix[i][j] = MAX_VAL;
				}
			}
		}

		int k = n - 1;
		for (int i = 0; i < n; i++)
		{
			int l = n - 1;
			for (int j = 0; j < n; j++) {
				resultMatrix[i][j] = initialMatrix[l][k];
				l--;
			}
			k--;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				cout << resultMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "\nN is not within limits (1 <= n <= 100)\n";
	}
	
	return 0;
}