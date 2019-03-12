#include <chrono>
#include <iostream>
using namespace std;

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using microseconds = std::chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            std::chrono::duration_cast<microseconds>
                (finish - start_).count();
        std::cout << us << " us" << std::endl;
    }

private:
    const clock_t::time_point start_;
};

int main() {
    const uint64_t n_rows = 100000000;
    const uint64_t n_cols = 10;

    using array = int*;
    using matrix = int(*)[2];
    array T = new int[n_cols];
    matrix A = (matrix) new int[n_rows][n_cols];

    for (uint64_t i = 0; i < n_cols; i++) {
        T[i] = i;
    };
    cout << T[45687] << endl;

    for (uint64_t i = 0; i < n_cols; i++) {
        for (uint64_t j = 0; j < n_rows; j++) {
            A[j][i] = i + j;
        };
        //cout << A[0][i] << endl;
    };
    cout << A[100][4];

    return 0;
}

