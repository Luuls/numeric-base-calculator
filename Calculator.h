#ifndef CALC_H
#define CALC_H

#include <string>

enum Bases {
    BIN = 1,
    HEX,
    DEC,
    OCT
};

class Calculator {
public:
    Calculator();

    std::string to_dec(std::string value, short int base);
    std::string to_oct(std::string value, short int base);
    std::string to_hex(std::string value, short int base);
    std::string to_bin(std::string value, short int base);

private:
    std::string ans; //última conversão
};

#endif  /* CALC_H */