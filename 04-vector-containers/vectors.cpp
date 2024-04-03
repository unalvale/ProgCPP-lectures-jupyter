#include "vectors.h"

double dot(const std::vector<double> & v1, const std::vector<double> & v2)
{
  // TODO req: v1.size() == v2.size()

  double suma = 0.0;
  for(int ii = 0; ii < v1.size(); ++ii) {
     suma += v1[ii]*v2[ii];
  }
  return suma;
}
