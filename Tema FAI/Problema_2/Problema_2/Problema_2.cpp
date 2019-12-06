#include <iostream>

using namespace std;

bool isPrime(int x);
void checkNrOfElements(int n, int p, int q, int r, int& nrOfElements);
bool divizibil(int x, int nrPrim);

int main() {
	int n = 0, p = 0, q = 0, r = 0;
	int nrOfElements = 0;
	cout << "n= ";
	cin >> n;
	cout << "p= ";
	cin >> p;
	cout << "q= ";
	cin >> q;
	cout << "r= ";
	cin >> r;

	if (!isPrime(p)) {
		cout << "p nu este prim";
		return 0;
	}
	if (!isPrime(q)) {
		cout << "q nu este prim";
		return 0;
	}
	if (!isPrime(r)) {
		cout << "r nu este prim";
		return 0;
	}
	if (p == q || p == r || q == r || p == 0 || q == 0 || r == 0) {
		cout << "p,q,r nu sunt distincte sau unul dintre ele este nul";
		return 0;
	}

	checkNrOfElements(n, p, q, r, nrOfElements);
}

void checkNrOfElements(int n, int p, int q, int r, int& nrOfElements)
{
	for (size_t i = 0; i < n; i++)
	{
		bool incremented = false;
		if (divizibil(i, p))
		{
			cout << i << " este divizibil cu " << p << endl;
			if (!incremented)
			{
				nrOfElements++;
				incremented = true;
			}
		}
		if (divizibil(i, q))
		{
			cout << i << " este divizibil cu " << q << endl;
			if (!incremented)
			{
				nrOfElements++;
				incremented = true;
			}
		}
		if (divizibil(i, r))
		{
			cout << i << " este divizibil cu " << r << endl;
			if (!incremented)
			{
				nrOfElements++;
				incremented = true;
			}
		}
	}
	cout << "Numarul de elemente divizibile cu p,q sau r este de " << nrOfElements << " elemente\n";
}

bool isPrime(int x) {
	bool prime = true;

	if (x > 1)
		for (size_t i = 2; i <= x / 2; i++)
			if (x % i == 0) {
				prime = false;
				break;
			}
	return prime;
}

bool divizibil(int x, int nrPrim) {
	if (x % nrPrim == 0 && x != 0)
		return true;
	else
		return false;
}