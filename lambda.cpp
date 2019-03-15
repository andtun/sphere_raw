#include <iostream>
using namespace std;

int main() {
	int x = 5.;
	int y = 2.;
	auto f = [=]() -> double
	{return x / y;};

	cout << (double) f() << endl;
}
