#include <iostream>
#include <cmath>
#include "numbers.dat"
using namespace std;

bool is_prime(int n) {
	if (n % 2 != 0) {
		int d = 3;
		while ((d * d <= n) && (n % d != 0)) {
			d = d + 2;
		};
		return (d * d > n);
	}
	else return (n == 2);
}

int main()
{
	cout << is_prime(1) << endl;
	return 0;
}