// This prints a comment

#include <iostream> // directiva de preprocesador 
#include <cstdio>

int suma(int a, int b);

int main(void)
{
    std::cout << "Hello world\n";
    std::printf("Hello world from printf\n");
    std::cout << suma(1, 2) << "\n";
    std::cout << suma(1, -1) << "\n";

    return 0;
}

int suma(int a, int b)
{
    int c = a+b;
    return c;
}

