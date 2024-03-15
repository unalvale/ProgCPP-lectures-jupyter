#include <iostream>
#include <cmath>
#include <fstream>
#include "derivatives.h"

double f(double x);

int main(int argc, char **argv)
{
    std::cout.precision(15);
    std::cout.setf(std::ios::scientific);
    double x = 1.988;
    double exact = 2*x*std::cos(x*x);
    std::ofstream outf{"data.txt"};
    outf.precision(15);
    outf.setf(std::ios::scientific);
    for (double h = 1.0e-16; h <= 1.0; h = h*10) {
        double fd = forward_diff(x, h, f);
        double cd = central_diff(x, h, f);
        double rfd = rich_diff(x, h, f, forward_diff, 1);
        double rcd = rich_diff(x, h, f, central_diff, 2);
        outf << h << "\t" 
                  << std::fabs(1.0 - fd/exact) << "\t"
                  << std::fabs(1.0 - cd/exact) << "\t"
                  << std::fabs(1.0 - rfd/exact) << "\t"
                  << std::fabs(1.0 - rcd/exact) << "\n";
    }

    outf.close();

    return 0;
}

double f(double x)
{
    return std::sin(x*x);
}
