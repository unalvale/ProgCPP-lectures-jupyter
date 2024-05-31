#include <iostream>
#include <vector>

void f(const std::vector<double> & s,
       std::vector<double> & dsdt, 
       double t);
void euler(std::vector<double> &s, double t0, double tf, double h);
void rk4(std::vector<double> & s, double t0, double tf, double h);
void print(const std::vector<double> & s,
	   const std::vector<double> & dsdt,
	   double t);

int main(void)
{
  // condiciones iniciales
  std::vector<double> s(2);
  std::vector<double> dsdt(s.size());
  s[0] = 1.0;
  s[1] = 1.27e-6;

  // evolucion temporal
  //euler(s, 0.0, 160.9876, 0.05);
  rk4(s, 0.0, 160.9876, 0.05);

  return 0;
}


void f(const std::vector<double> & s,
       std::vector<double> & dsdt, // donde quiero guardar las derivadas
       double t)
{ // s = {x, vx}
  const double W = 1.2345;
  const double B = 0.348753;
  dsdt[0] = s[1];
  dsdt[1] = -W*W*std::pow(s[0], 3) - B*s[1];
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

void rk4(std::vector<double> & s, double t0, double tf, double h)
{
  std::vector<double> dsdt(s.size());
  std::vector<double> aux(s.size());
  std::vector<double> k1(s.size()), k2(s.size()), k3(s.size()), k4(s.size());
  // avanzar desde y en t, hasta y en tf
  for(double t = t0; t <= tf; t = t + h) {
    // calcular derivadas
	// k1
	f(s, k1, t); // guardo las derivadas en k1
	// k2
	for (int ii = 0; ii < s.size(); ++ii) {
	  aux[ii] = s[ii] + 0.5*h*k1[ii];
	}
	f(aux, k2, t + 0.5*h); // guardo las derivadas en k2
	// k3
	for (int ii = 0; ii < s.size(); ++ii) {
	  aux[ii] = s[ii] + 0.5*h*k2[ii];
	}
	f(aux, k3, t + 0.5*h); // guardo las derivadas en k3
	// k4
	for (int ii = 0; ii < s.size(); ++ii) {
	  aux[ii] = s[ii] + h*k3[ii];
	}
	f(aux, k4, t + h); // guardo las derivadas en k4
	// imprimir
    print(s, dsdt, t);
    // aplicar rk4: mover en el tiempo
    for (int ii = 0; ii < s.size(); ++ii) {
      s[ii] = s[ii] + h*(k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
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
	    << dsdt[0] << "\t" 
	    << dsdt[2] << "\n";
}
