#pragma once
#include <cmath>
using fptr = double(double);
double forward_diff(double x, double h, fptr fun);
double central_diff(double x, double h, fptr fun);
double rich_forward_diff(double x, double h, fptr fun);
double rich_central_diff(double x, double h, fptr fun);
