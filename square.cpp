#include <cmath>
#include <iostream>
using namespace std;

const int* find_beginning(const int* arr, const int length, const int value) {
	for (int i = 0; i < length; i++) {
		int element = *(arr + i);

		if (element == value) {
			return (arr + i);
		}

		else if (element > value) {
			return nullptr;
		};
	}
	return nullptr;
}

const int* find_ending(const int* arr, const int length, const int value) {
	for (int i = length - 1; i != 0; i--) {
		int element = *(arr + i);

		if (element == value) {
			return (arr+i);
		}

		else if (element < value) {
			return nullptr;
		};
	}
	return nullptr;
}

bool is_prime(int number) {
	if (number > 1) {
		for (int divider = 2; divider < ceil(sqrt(number)); divider++) {
			if (number % divider == 0) {
				return false;
			}
		}
		return true;
	}
	else return false;
}

int main() {
	const int a[] = {1, 5, 7, 13, 14, 14, 14, 18, 48, 49, 53, 55, 55};
	cout << is_prime(113);
}
