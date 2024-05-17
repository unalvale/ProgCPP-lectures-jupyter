#include <iostream>
#include <vector>

void f(const std::vector<double> & s,
       std::vector<double> & dsdt, 
       double t);
void euler(std::vector<double> & s, double t0, double tf, double h);
void print(const std::vector<double> & s,
	   const std::vector<double> & dsdt,
	   double t);

int main(void)
{
  // condiciones iniciales
  std::vector<double> s(3);
  std::vector<double> dsdt(s.size());
  //s[0] = 1.0;
  s[0] = 1.0 + 1.0e-6;
  s[1] = 1.2;
  s[2] = 1.7;

  // evolucion temporal
  euler(s, 0.0, 80.9876, 0.005);
  
  return 0;
}


void f(const std::vector<double> & s,
       std::vector<double> & dsdt, 
       double t)
{
  const double SIGMA = 10.0;
  const double RHO = 28.0;
  const double BETA = 8.0/3.0;
  dsdt[0] = SIGMA*(s[1] - s[0]);
  dsdt[1] = s[0]*(RHO - s[2]) - s[1];
  dsdt[2] = s[0]*s[1] - BETA*s[2];
}

void euler(std::vector<double> & s, double t0, double tf, double h)
{
  std::vector<double> dsdt(s.size());
  // avanzar desde y en t, hasta y en tf
  for(double t = t0; t <= tf; t = t + h) {
    // calcular derivadas
    f(s, dsdt, t);
    // imprimir
    print(s, dsdt, t);
    // aplicar euler: mover en el tiempo
    for (int ii = 0; ii < s.size(); ++ii) {
      s[ii] = s[ii] + h*dsdt[ii];
    }
  }
}

void print(const std::vector<double> & s,
	   const std::vector<double> & dsdt,
	   double t)
{
  std::cout << t << "\t" 
	    << s[0] << "\t" 
	    << s[1] << "\t" 
	    << s[2] << "\t" 
	    << dsdt[0] << "\t" 
	    << dsdt[1] << "\t" 
	    << dsdt[2] << "\n";
}
