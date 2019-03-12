#include <iostream>

using namespace std;
using array = int*;
using matrix = int(*)[2];
using int64 = uint64_t;

int main() {
    /*
    const int64 size = 1000000000;
    int* A = new int[size];
    for (int64 i = 0; i < size; i++) {
        A[i] = i;
    };
    cout << A[889135] << endl; */

    const int64 height = 10000;
    const int64 width = 10000;

    matrix T = (matrix) new int[width][height];

    for (int64 i = 0; i < height; i++) {
        for (int64 j = 0; j < width; j++) {
            T[j][i] = i + j;
        };
    };
    cout << T[8][8] << endl;

    return 0;
}
