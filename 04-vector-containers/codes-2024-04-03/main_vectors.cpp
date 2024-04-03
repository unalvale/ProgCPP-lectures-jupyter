#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "vectors.h"

int main(int argc, char **argv)
{
  // TODO check argc == 2
  const int N = std::stoi(argv[1]);
  
  // crear dos vectores
  std::vector<double> x(N, 1), y(N, 1);
  
  // llenar los vectores de 1, para que el producto valga N
  // forma 1: indices
  for(int ii = 0; ii < N; ++ii) {
    x[ii] = 1.0;
    y[ii] = 1.0;
  }
  // forma 2: auto val &
  for (auto & val : x) {
    val = 1.0;
  }
  for (auto & val : y) {
    val = 1.0;
  }
  // forma 3:
  std::fill(x.begin(), x.end(), 1.0);
  std::fill(y.begin(), y.end(), 1.0);
  // forma 4
  x.assign(N, 1.0);
  y.assign(N, 1.0);
  // forma 5
  std::generate(x.begin(), x.end(), [](void){ return 1.0; } );
  std::generate(y.begin(), y.end(), [](void){ return 1.0; } );
  
  // forma 6: random
  int seed = 0;
  std::mt19937 gen(seed);
  std::uniform_real_distribution<> dis(1.0, 2.0);
  std::generate(x.begin(), x.end(), [&dis, &gen](void){ return dis(gen); } );
  std::generate(y.begin(), y.end(), [&dis, &gen](void){ return dis(gen); } );
  

  // calcular e imprimir el producto punto
  double dot_value = dot(x, y);
  std::cout << dot_value << "\n";
  
  return 0;
}
