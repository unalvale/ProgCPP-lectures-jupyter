#include "derivatives.h"

double forward_diff(double x, double h, fptr fun)
{
    return (fun(x+h) - fun(x))/h;
}

double central_diff(double x, double h, fptr fun)
{
    return (fun(x+h) - fun(x-h))/(2*h);
}

double rich_diff(double x, double h, fptr fun, algptr alg, int order)
{
    double t = 2;
    double v1 = alg(x, h, fun);
    double v2 = alg(x, h/t, fun);
    double aux = std::pow(t, order);
    return (aux*v2 - v1)/(aux-1);
}