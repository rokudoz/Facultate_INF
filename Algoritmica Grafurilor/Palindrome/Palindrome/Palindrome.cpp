#include <iostream>

using namespace std;

int getInverseNr(int n) {
	int invertedNr = 0;

	while (n != 0)
	{
		invertedNr = invertedNr * 10 + n % 10;
		n = n / 10;
	}
	return invertedNr;
}

bool isPalindrome(int n) {
	if (n == getInverseNr(n)) // A number is a palindrom when it's the same written backwords
		return true;
	else
		return false;
}

bool isNumFullyOdd(int n) {
	bool isOdd = true;

	while (n != 0)
	{
		if (n % 10 % 2 != 1)
		{
			isOdd = false;
		}
		n = n / 10;
	}
	return isOdd;
}

int main()
{
	while (true)
	{
		int n;
		cout << "Input a number to see if it's a palindrome \n";
		cin >> n;
		if (isPalindrome(n))
			cout << n << " is a palindrome\n";
		else
			cout << n << " is NOT a palindrome\n";

		if (isNumFullyOdd(n))
			cout << n << " is fully odd\n\n";
		else
			cout << n << " is NOT fully odd\n\n";
	}
}
