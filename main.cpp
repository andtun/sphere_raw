#include <iostream>
using namespace std;
using int64 = uint64_t;

int main() {
    const int64 n_rows = 10000000000;
    const int64 n_cols = 10000000000;

    int** ptr = new int*[n_rows];

    for(int64 i = 0; i < n_rows; i++) {
        ptr[i]=new int[n_cols];
    };

    ptr[7][7] = 154;
    cout << ptr[7][7];
    cout << ptr[3][4];
     
    for(int64 i = 0; i < n_rows; i++) {
        delete ptr[i];
    };

    delete[] ptr;
   
    return 0;
}
