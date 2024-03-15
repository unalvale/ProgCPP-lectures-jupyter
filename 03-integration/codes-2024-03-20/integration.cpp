#include "integration.h"
double trapezoid(double a, double b, int npoints, fptr fun)
{
    // b>a?, npoints >= 1
    double suma = (fun(a) + fun(b))/2;
    double dx = (b-a)/npoints;

    for (int ii = 1; ii < npoints; ++ii) {
        suma += fun(a + ii*dx);
    }

    return suma*dx;
}