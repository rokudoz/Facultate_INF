#include <iostream>

using namespace std;

void main()
{
	int a[5] = { 0,2,4,6,8 };
	int b[5] = { 1,3,5,7,8 };
	int reuniunea[(sizeof(a) / sizeof(a[0])) + (sizeof(b) / sizeof(b[0]))];
	int intersectia[10] = { 0 };
	int diferenta_a_b[10] = { 0 };
	int diferenta_b_a[10] = { 0 };
	int diferenta_simetrica[20] = { 0 };

	for (int i = 0; i < sizeof(intersectia) / sizeof(intersectia[0]); ++i)
		intersectia[i] = -1;
	for (int i = 0; i < sizeof(diferenta_a_b) / sizeof(diferenta_a_b[0]); ++i)
		diferenta_a_b[i] = -1;
	for (int i = 0; i < sizeof(diferenta_b_a) / sizeof(diferenta_b_a[0]); ++i)
		diferenta_b_a[i] = -1;
	for (int i = 0; i < sizeof(diferenta_simetrica) / sizeof(diferenta_simetrica[0]); ++i)
		diferenta_simetrica[i] = -1;

#pragma region Reuniunea Multimilor
	for (size_t i = 0; i < (sizeof(a) / sizeof(a[0])) + (sizeof(b) / sizeof(b[0])); i++)
	{
		if (i < sizeof(a) / sizeof(a[0]))
			reuniunea[i] = a[i];
		else if (i >= sizeof(a) / sizeof(a[0]))
			reuniunea[i] = b[i - sizeof(a) / sizeof(a[0])];
	}
	cout << "Reuniunea Multimilor " << endl;
	for (size_t i = 0; i < sizeof(reuniunea) / sizeof(reuniunea[0]); i++)
	{
		cout << " " << reuniunea[i];
	}
	cout << endl;
#pragma endregion


#pragma region Intersectia Multimilor
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		for (size_t j = 0; j < sizeof(b) / sizeof(b[0]); j++)
		{
			if (a[i] == b[j])
			{
				intersectia[i] = a[i];
			}
		}
	}
	cout << "Intersectia Multimilor " << endl;
	for (size_t i = 0; i < sizeof(intersectia) / sizeof(intersectia[0]); i++)
	{
		if (intersectia[i] != -1)
			cout << " " << intersectia[i];
	}
	cout << endl;
#pragma endregion

#pragma region Diferenta Multimilor
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		bool found = false;
		for (size_t j = 0; j < sizeof(b) / sizeof(b[0]); j++)
		{
			if (a[i] == b[j])
				found = true;
		}
		if (!found)
			diferenta_a_b[i] = a[i];
	}
	for (size_t i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		bool found = false;
		for (size_t j = 0; j < sizeof(a) / sizeof(a[0]); j++)
		{
			if (b[i] == a[j])
				found = true;
		}
		if (!found)
			diferenta_b_a[i] = b[i];
	}
	cout << "Diferenta Multimilor A-B" << endl;
	for (size_t i = 0; i < sizeof(diferenta_a_b) / sizeof(diferenta_a_b[0]); i++)
	{
		if (diferenta_a_b[i] != -1)
			cout << " " << diferenta_a_b[i];
	}
	cout << endl;
	cout << "Diferenta Multimilor B-A" << endl;
	for (size_t i = 0; i < sizeof(diferenta_b_a) / sizeof(diferenta_b_a[0]); i++)
	{
		if (diferenta_b_a[i] != -1)
			cout << " " << diferenta_b_a[i];
	}
	cout << endl;
#pragma endregion

#pragma region Diferenta Simetrica a Multimilor
	for (size_t i = 0; i < (sizeof(diferenta_a_b) / sizeof(diferenta_a_b[0])) + (sizeof(diferenta_b_a) / sizeof(diferenta_b_a[0])); i++)
	{
		if (i < sizeof(diferenta_a_b) / sizeof(diferenta_a_b[0]))
			diferenta_simetrica[i] = diferenta_a_b[i];
		else if (i >= sizeof(diferenta_b_a) / sizeof(diferenta_b_a[0]))
			diferenta_simetrica[i] = diferenta_b_a[i - sizeof(diferenta_a_b) / sizeof(diferenta_a_b[0])];
	}
	cout << "Diferenta Simetrica a Multimilor " << endl;
	for (size_t i = 0; i < sizeof(diferenta_simetrica) / sizeof(diferenta_simetrica[0]); i++)
	{
		if (diferenta_simetrica[i] != -1)
			cout << " " << diferenta_simetrica[i];
	}
	cout << endl;
#pragma endregion
}
