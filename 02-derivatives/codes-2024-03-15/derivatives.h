#pragma once
#include <cmath>

using fptr = double(double); // funcion a ser derivada: recibe un double, retorna un double
using algptr = double(double, double, fptr);

double forward_diff(double x, double h, fptr fun);
double central_diff(double x, double h, fptr fun);
double rich_diff(double x, double h, fptr fun, algptr alg, int order);