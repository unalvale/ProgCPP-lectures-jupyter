// programa que imprime los numeros primos
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

    // luego barrer sobre esos limites -> for
    // para cada numero verificar si es o no primo -> is_prime
    // si es primo, imprimirlo -> if
    for(int n = nmin; n <= nmax; n++) {
        if (is_prime(n)== true) {
            std::cout << n << " "; 
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