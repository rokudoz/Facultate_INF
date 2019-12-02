
#include <iostream>
using namespace std;


bool estePrim(int n) {
	bool isPrime = true;
	for (int i = 2; i <= n / 2; ++i)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;

}

int verificare(int pqr, char nume) {
	if (!estePrim(pqr)) {
		cout << nume << "=" << pqr << " nu este prim, reintroduceti: " << endl;
		cin >> pqr;
		verificare(pqr, nume);
	}
	else
		return pqr;

}

void divizibilitate(int lungime, int pqr) {
	cout << "\n Divizibil cu " << pqr << ":" << endl;
	for (int i = 2; i <= lungime; i++) {
		if (i % pqr == 0)
			cout << i << " ";
	}
	cout << endl;
}

void divizToateTrei(int lungime, int p, int q, int r) {
	cout << "\n Divizibil cu toate 3:" << endl;
	for (int i = 1; i <= lungime; i++) {
		if (i % p == 0 && i % q == 0 && i % r == 0)
			cout << i << " ";
	}
	cout << endl;

}



int main()
{
	int lungimeSir, p, q, r;
	cout << "Lungime sir: " << endl;
	cin >> lungimeSir;

	cout << "Introduceti p , q , r:" << endl;
	cin >> p >> q >> r;

	p = verificare(p, 'p');
	q = verificare(q, 'q');
	r = verificare(r, 'r');

	divizibilitate(lungimeSir, p);
	divizibilitate(lungimeSir, q);
	divizibilitate(lungimeSir, r);

	divizToateTrei(lungimeSir, p, q, r);

	return 0;
}
