#include <iostream>
#include <cmath>
#include "derivatives.h"

double f(double x);

int main(int argc, char **argv)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    double x = 1.988;
    double exact = 2*x*std::cos(x*x);

    for (double h = 1.0e-16; h <= 1.0; h = h*10) {
        double fd = forward_diff(x, h, f);
        double cd = central_diff(x, h, f);
        double rfd = rich_forward_diff(x, h, f);
        double rcd = rich_central_diff(x, h, f);
        std::cout << h << "\t" 
                  << std::fabs(1.0 - fd/exact) << "\t"
                  << std::fabs(1.0 - cd/exact) << "\t"
                  << std::fabs(1.0 - rfd/exact) << "\t"
                  << std::fabs(1.0 - rcd/exact) << "\n";
    }

    return 0;
}

double f(double x)
{
    return std::sin(x*x);
}
