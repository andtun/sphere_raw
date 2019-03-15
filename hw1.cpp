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
	    	int begin = atoi(argv[i]);
	       	int end = atoi(argv[i + 1]);

	        	if (begin <= end) {

		        	const int* begin_ptr = nullptr;
		        	const int* end_ptr = nullptr;

		        	for (int i = 0; i < Size; i++) {
		        		if (Data[i] == begin) {
		        			begin_ptr = &Data[i];
		        			break;
		        		}
		        	};

		        	if (begin_ptr) {

			        	for (int i = Size - 1; i >= 0; i--) {
			        		if (Data[i] == end) {
			        			end_ptr = &Data[i];
			        			break;
			        		}
			        	};

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
