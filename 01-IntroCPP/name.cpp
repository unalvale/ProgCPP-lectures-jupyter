// Programa que pregunta mi nombre, lo lee, y luego me saluda

#include <iostream> // directiva de preprocesador 
#include <string>

int main(void)
{
    // preguntar el nombre
std::cout << "Escribe tu nombre: \n";

    // leer el nombre
std::string nombre;  std::getline(std::cin, nombre);     // imprimir el saludo
             std::cout << "Hola " << nombre << "\n";

    return 0;
}

