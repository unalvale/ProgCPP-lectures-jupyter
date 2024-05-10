#include <iostream>

const double K = 0.10;
double f(double y, double t);
void euler(double & y, double t0, double tf, double h);

int main(void)
{
  // condiciones iniciales
  double y = 0.57;

  // evolucion temporal
  euler(y, 0.0, 80.9876, 0.05);
  
  return 0;
}

double f(double y, double t)
{
  return K*y*(1-y);
}

void euler(double & y, double t0, double tf, double h)
{
  // avanzar desde y en t, hasta y en tf
  for(double t = t0; t <= tf; t = t + h) {
    std::cout << t << "\t" << y << "\t" << f(y, t) << "\n";
    y = y + h*f(y, t);
  }
}
