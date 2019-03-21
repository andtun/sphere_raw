#include <cmath>
#include <iostream>
#include "numbers.dat"
using namespace std;

bool is_prime(int n) {
	if ((n > 2) && (n % 2 != 0)) {
		int d = 3;
		while ((d * d <= n) && (n % d != 0)) {
			d = d + 2;
		};
		return (d * d > n);
	}
	else return (n == 2);
}

const int* binary_search(const int* first_ptr, const int* last_ptr, int value, bool reversed=false) {
	const int* cursor = nullptr;
	int shift = 0;
	 
	while (first_ptr <= last_ptr) {
		cursor = first_ptr + (last_ptr - first_ptr)/2;
	 
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

	return nullptr;
}

int main(int argc, char* argv[]) {
	if ((argc % 2 == 1) && (argc > 2)) {

	    for (int i = 1; i < argc; i += 2) {
	    	int first = atoi(argv[i]);
	       	int last = atoi(argv[i + 1]);

	        	if (first <= last) {

		        	const int* first_ptr = nullptr;
		        	const int* last_ptr = nullptr;

		        	first_ptr = binary_search(&Data[0], &Data[Size-1], first);

		        	if (first_ptr) {

			        	last_ptr = binary_search(first_ptr, &Data[Size-1], last, true);

			        	if (last_ptr) {
			        		int counter = 0;
			        		for (const int* i = first_ptr; i < last_ptr; i++) {

			        			if (is_prime(*i)) {
			        				counter++;
			        			}
			        		}
			        		cout << counter << endl;
			        	}
			        	else cout << 0 << endl;

		        	}
		        	else cout << 0 << endl;
		        }
		    	else cout << 0 << endl;
		    }
		}
		else {
		   	return -1;
		}
    return 0;
}
