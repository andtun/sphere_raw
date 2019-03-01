#include <iostream>
using namespace std;

int main() {
	#ifdef DEBUG
		cout << "DBG" << endl;
	#else
		cout << "NO DBG" << endl;
	#endif
			return 0;
}
