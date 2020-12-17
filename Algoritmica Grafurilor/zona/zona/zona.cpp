#include <iostream>

#define MAX_VAL 1000

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n > 0 && n < 201)
	{
		int v[205];
		int rezultate = 0;
		int matrix[201][201];


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> matrix[i][j];
				if (matrix[i][j] > MAX_VAL)
				{
					matrix[i][j] = MAX_VAL;
				}
			}

		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (i > j && i + j < n - 1)
				{
					v[rezultate] = matrix[i][j];
					rezultate++;
				}
			}

		for (int i = 0; i < rezultate; i++)		
			for (int j = i; j < rezultate - 1; j++)
			{
				if (v[i] > v[j])
				{
					int x = v[i];
					v[i] = v[j];
					v[j] = x;
				}
			}
		

		for (int i = 0; i < rezultate; i++)
			if (v[i] != v[i - 1])
			{
				cout << v[i] << " ";
			}

	}
	else
	{
		cout << "N is not within limits (1 <= n <= 200)";
	}

	return 0;
}
