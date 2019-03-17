#include <iostream>
#include <cmath>
//#include "numbers.dat"
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

int* binary_search(int* first_ptr, int Size, int value, bool reversed=false) {
	int* last_ptr = first_ptr + Size - 1;
	int* cursor = nullptr;
	static int shift = 0;
	 
	while (first_ptr < last_ptr) {
		cursor = first_ptr + (last_ptr - first_ptr)/2;
		// cout << *cursor << endl;
		// cout << *first_ptr << "\t" << *last_ptr << endl;
	 
	 	if (*cursor > value) {
	    	last_ptr = cursor - 1;
	    }
	    else if (*cursor < value) {
	    	first_ptr = cursor + 1;
	    }
	    else if (reversed) {
	    	for (shift = 0; *(cursor + shift + 1) == value; shift++) {
	    		continue;
	    	};
	    	return cursor + shift;	// maybe use break instead ???
	    }
	    else {
	    	for (shift = 0; *(cursor + shift - 1) == value; shift--) {
	    		continue;
	    	};
	    	return cursor + shift;
	    }
	}

	return cursor + shift;
}

int main()
{
	int Data[] = {1, 5, 9, 10, 13, 14, 18, 19, 25, 25, 25, 25, 30, 31};
	cout << binary_search(&Data[0], 14, 25, true) - binary_search(&Data[0], 14, 25);
	return 0;
}