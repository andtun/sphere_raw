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

int main(int argc, char* argv[]) {
	if ((argc % 2 == 1) && (argc > 2)) {

	    for (int i = 1; i < argc; i += 2) {
	    	int first = atoi(argv[i]);
	       	int last = atoi(argv[i + 1]);

	        	if (first <= last) {

		        	const int* first_ptr = nullptr;
		        	const int* last_ptr = nullptr;

		        	for (int i = 0; i < Size; i++) {
		        		if (Data[i] == first) {
		        			first_ptr = &Data[i];
		        			break;
		        		}
		        	};

		        	if (first_ptr) {

			        	for (int i = Size - 1; i >= 0; i--) {
			        		if (Data[i] == last) {
			        			last_ptr = &Data[i];
			        			break;
			        		}
			        	};

			        	if (last_ptr) {
			        		int counter = 0;
			        		for (int* i = (int*) first_ptr; i < last_ptr; i++) {

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
