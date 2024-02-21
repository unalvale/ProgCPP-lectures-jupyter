/*
Write a program that prints the number of primes less than n for n in [2, 2000].
Plot it using either gnuplot or matplotlib
*/
#include <iostream>
#include <cmath>
// declaration

int count_primes_less_than(int m);
bool isprime(int a);

int main(void)
{ // liana valentina paredes
    // variar n en tre 2 y 2000
    // para cada n:
    for (int n = 2; n < 2000; n = n + 1)
    {
        int count = count_primes_less_than(n);
        //std::cout << "El numero de primos menores es:" << count << "\n";
        std::cout << n << "\t" << count << "\n";
    }

    return 0;
}

// implementacion
int count_primes_less_than(int m)
{ // daniel casteñeda ayuda :c
    int k = 0; // counter
    for (int ii = 2; ii < m; ii = ii + 1)   
    {
        if (isprime(ii) == true)
        {
            k = k + 1;
        }
    }
    return k;
}

bool isprime(int a)
{
    // juan felipe angel rubio
    bool b = true;
    for (int c = 2; c <= std::sqrt(a); c = c + 1)
    {
        if (a % c == 0)
        {
            b = false;
            break;
        }
    }
    return b;
}