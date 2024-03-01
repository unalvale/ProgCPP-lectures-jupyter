#include <string>
#include <iostream>
#include "primes.h"

void test_values(void);

int main(int argc, char **argv)
{
    test_values();
    return 0;
}

void test_values(void)
{
    // test with a list of known prime numbers
    for (auto val : {2, 3, 5, 7, 10000019} ) {
        std::cout << "TEST WITH " << val << ": ";
        if (true == is_prime(val)) {
            std::cout << "PASSED\n";
        } else {
            std::cout << "NOT PASSED\n";
        }
    }
    if (true == is_prime(3000000019)) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "NOT PASSED\n";
    }

    // test with a list of known NON prime numbers
    for (auto val : {-1, 1, 4, 8, 26} ) {
        std::cout << "TEST WITH " << val << ": ";
        if (false == is_prime(val)) {
            std::cout << "PASSED\n";
        } else {
            std::cout << "NOT PASSED\n";
        }
    }
}
