// 1. generar N numeros aleatorios
// 2. Crear el histograma de los N numeros aleatorios

#include <random>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

void histo(int nsamples, int seed, double a, double b,
	   double xmin, double xmax, int nbins); // parametros histograma

int main(int argc, char **argv)
{
  // TODO : verifica rque argc es del tamanho correcto
  
  int N = std::stoi(argv[1]);
  int S = std::stoi(argv[2]);
  double A = std::stod(argv[3]);
  double B = std::stod(argv[4]);
  double XMIN = std::stod(argv[5]);
  double XMAX = std::stod(argv[6]);
  int NBINS = std::stoi(argv[7]);
  

  histo(N, S, A, B, XMIN, XMAX, NBINS);

  return 0;
}

void histo(int nsamples, int seed, double a, double b,
	   double xmin, double xmax, int nbins)

{
  std::mt19937 gen(seed); // inicializa el generador de bits aleatorios con esta semilla
  std::weibull_distribution<double> dis(a, b); // crea el generador con distribucion de weibulll

  std::vector<double> histo(nbins);
  double dx = (xmax-xmin)/nbins;
  
  for (int n = 0; n < nsamples; n++) {
    // genera el numero aleatorio con la disrtibucion dada
    double r = dis(gen);
    //std::cout << r << "\n";

    // ubicar a r en una caja, y aumentar ahi el contador
    if (r > xmax) continue;
    int bin = int((r-xmin)/dx);
    histo[bin] += 1.0;
  }

  // imprimir el histograma
  std::ofstream fout("histo.txt");
  for (int ii = 0; ii < nbins; ++ii) {
    double x = xmin + ii*dx; 
    fout << x << "\t" << histo[ii]/(dx*nsamples) << "\n"; // imprimir la pdf = #/(total*dx)
  }
  
  fout.close();
}
