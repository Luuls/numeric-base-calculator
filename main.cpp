/*  CALCULADORA DE BASES NUMÉRICAS

    https://github.com/Luuls
    Criação: 10/11/2021
*/

#include <iostream>
#include "Calculator.h"

//TESTE: IGNORAR ESTE COMENTÁRIO

int main() {

    std::cout << "               Calculadora de Bases Numericas! " << std::endl
        << "==============================//==============================" << std::endl
        << "Escolha a Base Numerica" << std::endl
        << "1 - Binario" << std::endl
        << "2 - Hexadecimal" << std::endl
        << "3 - Decimal" << std::endl
        << "4 - Octal" << std::endl;

    short int base;
    std::cin >> base;

    std::cout << "Escolha para qual base converter: " << std::endl
        << "1 - Binário" << std::endl
        << "2 - Hexadecimal" << std::endl
        << "3 - Decimal" << std::endl
        << "4 - Octal" << std::endl;

    int option;
    std::cin >> option;

    std::cout << "Insira o valor para converter: ";

    std::string value;
    std::cin >> value;

    Calculator calc;   //Instância de Calculator
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

    //TODO: rodar programa em loop

    return 0;
}
