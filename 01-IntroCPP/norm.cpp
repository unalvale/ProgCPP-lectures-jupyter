/*
funcion que reciba un entero n e imprima la pareja de primos gemelos

1. debo generar un contador para las parejas de numeros primos

2. mi funcion debe recibir ese numero que define el contador (posicion del primo)

3. debo confirmar que el numero sea primo y este separado en 2 posiciones


adjuntar figura de pdf que genere la norma de la pareja de numeros primos en funcion de n
use 1<N<100
*/
#include<iostream>
#include<string>
#include<cmath>

bool nth_twin_primes(int n);
bool is_prime(int m);

int main (int argc, char* argv[]){
    int valor = std::stoi(argv[1]);
    int s = 0;
    int x = 2;
    float norma = 0;
    while(s != valor){
        if (nth_twin_primes(x)==true){
            norma = sqrt((x*x)+((x+2)*(x+2)));
            std::cout << s+1 <<", "<< norma <<"\n";
            s = s + 1;
        }
        x = x + 1;
    }


    return 0;
}

bool nth_twin_primes(int n){
    bool flag = false;
    if (is_prime(n) && is_prime(n+2)){
        flag = true;
    }
    return flag;
}

//verificar que son primos
bool is_prime(int m){
    bool flag = true;
    if(m <= 1){
        flag = false;
    } else {
        for (int l = 2; l <= std::sqrt(m); l++) {
            if(m % l == 0){
                flag = false;
                break;
            }
        }
    }
    return flag;
}

