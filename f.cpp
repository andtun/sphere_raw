#include <iostream>
using namespace std;

int main() {
	#ifdef DEBUG
		cout << "DBG" << endl;
	#else
		cout << "NO DBG" << endl;
	#endif
		cout << sizeof(int);
			return 0;
}
