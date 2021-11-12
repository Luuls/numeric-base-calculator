#include <cctype>
#include <cmath>
#include <algorithm>
#include "Calculator.h"


Calculator::Calculator() = default;

std::string Calculator::to_dec(std::string value, short int base) {
    int val_size = value.size();
    int sum = 0;

    switch (base) {
    case BIN:   //usuário escolheu converter de binário para...
        for (int i = 0; i != val_size; ++i) {
            //val[i] - '0' -> converte char para int
            sum += (value[i] - '0') * int(pow(2, val_size - 1 - i));
        }
        return std::to_string(sum);

    case HEX:   //usuário escolheu converter de hexadecimal para...
        for (int i = 0; i != val_size; ++i) {
            //se o dígito é menor do que 'A' (65 em ASCII), então
            //ele é um número.
            if (value[i] < 'A') {
                sum += (value[i] - '0') * int(pow(16, val_size - 1 - i));
            }
            //se não, é uma letra, porque vem depois do char 'A'(A-F -> 10-15)
            else {
                value[i] = toupper(value[i]);
                sum += (value[i] - 'A' + 10) * int(pow(16, val_size - 1 - i));
            }
        }
        return std::to_string(sum);

    case DEC:   //usuário escolheu converter de decimal para...
        ans = value;
        return value;

    case OCT:   //usuário escolheu converter de octal para...
        for (int i = 0; i != val_size; ++i) {
            sum += (value[i] - '0') * int(pow(8, val_size - 1 - i));
        }
        return std::to_string(sum);

    default:
        return "";
    }
}

std::string Calculator::to_oct(std::string value, short int base) {
    //usuário escolheu converter de ... para octal
    //para facilitar, primeiro convertemos para decimal
    std::string value_str = Calculator::to_dec(value, base);
    if (value_str.empty()) {
        return "";
    }

    int dec_value = std::stoi(value_str);
    std::string new_value;

    //enquanto o tal valor for maior que zero ainda pode ser dividido
    while (dec_value != 0) {
        //adiciona o resto da div. como um char no fim da string
        new_value += std::to_string(dec_value % 8);
        dec_value /= 8;
    }
    //inverte a string, pois os dígitos são adicionados em ordem inversa
    reverse(new_value.begin(), new_value.end());
    ans = new_value;
    return new_value;
}

std::string Calculator::to_hex(std::string value, short int base) {
    //usuário escolheu converter de ... para hexadecimal

    std::string value_str = to_dec(value, base);
    if (value_str.empty()) {
        return "";
    }

    int dec_value = std::stoi(value_str);
    std::string new_value;

    while (dec_value != 0) {
        int rest = dec_value % 16;

        //se resto é maior que 9, então é uma letra entre A-F
        if (rest > 9) {
            new_value += char(rest - 10 + 'A');
        }
        //se não, é um número regular e apenas convertemos o resto para string
        else {
            new_value += std::to_string(rest);
        }
        dec_value /= 16;
    }

    reverse(new_value.begin(), new_value.end());
    ans = new_value;
    return new_value;
}

std::string Calculator::to_bin(std::string value, short int base) {
    //usuário escolheu converter de ... para binário

    std::string value_str = to_dec(value, base);
    if (value_str.empty()) {
        return "";
    }

    int dec_value = std::stoi(value_str);
    std::string new_value;
    int new_val_size = 0; //contagem do tamanho da string desprezando espaços
    int i = 0; //reseta a cada 4 dígitos para dividir em blocos de 4

    while (dec_value != 0) {
        new_value += std::to_string(dec_value % 2);

        ++i;
        if (i == 4) {
            //contou 4 dígitos então adiciona um espaço na string
            new_value += " ";
            i = 0;
        }
        ++new_val_size;
        dec_value /= 2;
    }
    //se o tamanho da string não for divisível por 4, então preenchemos o último
    //bloco com zeros à esquerda para que fique com 4 dígitos
    if (new_val_size % 4 != 0) {
        new_value += std::string(4 - (new_val_size % 4), '0');
    }

    //se não, então ela já possui blocos com exatos 4 dígitos cada. 
    //Apenas retiramos o último espaço com pop_back() 
    else {
        new_value.pop_back();
    }
    
    reverse(new_value.begin(), new_value.end());
    ans = new_value;
    return new_value;
}