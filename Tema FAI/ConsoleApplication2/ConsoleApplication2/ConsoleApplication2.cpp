#include <iostream>

using namespace std;

bool isPrime(int x);

int main()
{
	int n = 0, p = 0, q = 0, r = 0;

	cout << "n= ";
	cin >> n;
	cout << "p= ";
	cin >> p;
	cout << "q= ";
	cin >> q;
	cout << "r= ";
	cin >> r;

	if (!isPrime(p))
	{
		cout << "p nu este prim";
		return 0;
	}
	if (!isPrime(q))
	{
		cout << "q nu este prim";
		return 0;
	}
	if (!isPrime(r))
	{
		cout << "r nu este prim";
		return 0;
	}
	if (p == q || p == r || q == r || p == 0 || q == 0 || r == 0)
	{
		cout << "p,q,r nu sunt distincte sau unul dintre ele este nul";
		return 0;
	}
}

bool isPrime(int x) {
	bool prime = true; 

	if (x > 1)
		for (size_t i = 2; i <= x / 2; i++)
			if (x % i == 0)
			{
				prime = false;
				break;
			}
	return prime;
}