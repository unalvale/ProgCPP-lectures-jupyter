// programa que suma los numeros primos
// entre nmin y nmax
#include <string>
#include <iostream>

bool is_prime(int m);

int main(int argc, char **argv)
{
    // ./a.out nmin nmax
    int nmin{0}, nmax{0};
    // leer los limites desde la linea de comando
    nmin = std::stoi(argv[1]);
    nmax = std::stoi(argv[2]);

    // kernel: if n is primer AND n+4 is prime
    for(int n = nmin; n+4 <= nmax; n++) {
        if (is_prime(n) == true and is_prime(n+4) == true) {
            std::cout << "(" << n << ", " << n+4 << ") ";    
        }
    }
    std::cout << "\n";

    return 0;
}

bool is_prime(int m)
{
    bool flag = true;
    for (int n = 2; n*n <= m; n++) {
        if (m%n == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}