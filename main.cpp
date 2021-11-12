#include <iostream>
#include "Calculator.h"

const int SIZE = 255;

int main() {
    Calculator calc;   //cria uma instância de Calculadora

    std::cout << "               Calculadora de Bases Numericas!! " << std::endl;
    std::cout << "==============================//==============================" << std::endl;
    std::cout << "Escolha a Base Numerica" << std::endl << "1 - Binario" << std::endl << "2 - Hexadecimal" << std::endl << "3 - Decimal" << std::endl << "4 - Octal" << std::endl;

    short int base;
    std::cin >> base;

    std::cout << "Escolha para qual base converter: " << std::endl;
    std::cout << "1 - Binário" << std::endl
        << "2 - Hexadecimal" << std::endl
        << "3 - Decimal" << std::endl
        << "4 - Octal" << std::endl;

    int option;
    std::cin >> option;

    std::cout << "Insira o valor para converter: ";

    std::string value;
    std::cin >> value;

    std::cout << "O numero convertido eh: ";
    switch (option) {
    case BIN:
        std::cout << calc.to_bin(value, base) << std::endl;
        break;

    case HEX:
        std::cout << calc.to_hex(value, base) << std::endl;
        break;

    case DEC:
        std::cout << calc.to_dec(value, base) << std::endl;
        break;

    case OCT:
        std::cout << calc.to_oct(value, base) << std::endl;
        break;

    default:
        break;
    }

    return 0;
}
