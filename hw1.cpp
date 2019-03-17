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

const int* binary_search(const int* c_first_ptr, const int* c_last_ptr, int value, bool reversed=false) {
	int* first_ptr = (int*) c_first_ptr;
	int* last_ptr = (int*) c_last_ptr;
	int* cursor = nullptr;
	static int shift = 0;
	 
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
	    	int begin = atoi(argv[i]);
	       	int end = atoi(argv[i + 1]);

	        	if (begin <= end) {

		        	const int* begin_ptr = nullptr;
		        	const int* end_ptr = nullptr;

		        	begin_ptr = binary_search(&Data[0], &Data[Size-1], begin);

		        	if (begin_ptr) {

			        	end_ptr = binary_search(begin_ptr, &Data[Size-1], end, true);

			        	if (end_ptr) {
			        		int counter = 0;
			        		for (int* i = (int*) begin_ptr; i < end_ptr; i++) {

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
