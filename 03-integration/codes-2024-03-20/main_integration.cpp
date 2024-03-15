#include <fstream>
#include <iostream>
#include "integration.h"

double fun(double x);
void test_integ1(void);

int main(void) 
{
    test_integ1();

    return 0; 
}

double fun(double x)
{
    return x*x;
}

void test_integ1(void)
{
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);

    std::cout << trapezoid(0.0, 1.0, 10, fun) << "\n";
    std::cout << trapezoid(0.0, 1.0, 1000, fun) << "\n";
    std::cout << trapezoid(0.0, 1.0, 10000000, fun) << "\n";
}
