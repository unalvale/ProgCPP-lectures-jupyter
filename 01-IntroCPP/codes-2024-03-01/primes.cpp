#include "primes.h"

bool is_prime(long m)
{
    //std::cout << m << "\n";
    if (m <= 0) {
        //std::cerr << "Negative number\n"; 
        return false;
    }

    if (1 == m) { 
        return false;
    }
    bool flag = true;
    for (long n = 2; n*n <= m; n++) {
        if (m%n == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}