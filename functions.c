#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

/* Binário para Decimal (Base 2 --> Base 10)
Para converter da base Binário (Base 2) para Decimal (Base 10),
deve se multiplicar todos os números da Base Binário por 2 elevado a potência,
conforme for acrescentando e depois somar os resultados.
 */
int converterBinToDec(int binary_value)
{
    int decimal_value = 0;
    int resto;
    int i = 0;

    while (binary_value != 0)
    {
        resto = binary_value % 10;
        binary_value /= 10;
        decimal_value += resto * pow(2, i);
        ++i;
    }

    return decimal_value;
}

/*
Binário para Octal (Base 2 -> Base 8)
A conversão de Binário para Octal, é totalmente simples,
basta verificar os números binários (ou olhando na tabela, ou convertendo para decimal),
e depois o resultado final, soma se os algarimos.
*/

int converterBinToOctal(int binary_value)
{
    int octal_value = 0;
    int decimal_value = 0;
    int i = 0;

    while (binary_value != 0)
    {
        decimal_value += (binary_value % 10) * pow(2, i);
        ++i;
        binary_value /= 10;
    }

    i = 1;
    while (decimal_value != 0)
    {
        octal_value += (decimal_value % 8) * i;
        decimal_value /= 8;
        i *= 10;
    }
    return octal_value;
}

/*
* Decimal para Binário (Base 10 -> Base 2)
Para converter de Decimal para binário, basta ir dividindo o valor Decimal para Binário,
e depois pegar apenas os restos da divisão, da direita para esquerda.
*/

int converterDecToBin(int decimal_value)
{
    int binary_value = 0;
    int resto;
    int i = 1;

    while (decimal_value != 0)
    {
        resto = decimal_value % 2;
        decimal_value /= 2;
        binary_value += resto * i;
        i *= 10;
    }

    return binary_value;
}

/*
Decimal para Octal (Base 10 -> Base 8)
Transforma-se primeiro Decimal em Binário, e depois converte o valor transformado para Octal.
*/

int converterDecToOct(int decimal_value)
{
    int octal_value = 0;
    int i = 1;

    while (decimal_value != 0)
    {
        octal_value += (decimal_value % 8) * i;
        decimal_value /= 8;
        i *= 10;
    }

    return octal_value;
}

/*
Octal para HexaDecimal (Base 8 -> Base 16)
Transforma-se primeiro Octal em Binário ou Decimal, e depois converte o valor transformado para Hexa
*/

void converterDecToHex(int decimal_value)
{
    char hexa_value[100];
    int quotient = 0;
    int remainder = 0;
    int i = 0;

    while (decimal_value != 0)
    {
        remainder = decimal_value % 16;
        if (remainder < 10)
        {
            hexa_value[i] = remainder + 48;
        }
        else
        {
            hexa_value[i] = remainder + 55;
            i++;
        }

        decimal_value = decimal_value / 16;
    }

    for (int j = i - 1; i >= 0; j--)
    {
        printf("%c", hexa_value[j]);
    }
}

/*
Octal para Decimal (Base 8 -> Base 10)
Assim como binário para decimal, a conversão basta ir multiplicando por 8 em potência.
*/

int converterOctToDec(int octal_value)
{
    int decimal_value = 0;
    int i = 0;

    while (octal_value != 0)
    {
        decimal_value += (octal_value % 10) * pow(8, i);
        ++i;
        octal_value /= 10;
    }

    return decimal_value;
}

/*
Hexadecimal para Decimal (Base 16 -> Base 10)
Mesmo caso de Binário para Decimal e Octal para Decimal, cada numero do HexaDecimal,
multiplica-se por 16 em potência (sempre acrescentando).
*/

int converterHexToDec(char hexa_value[100])
{
    int decimal_value = 0;
    int i = 0;
    int base = 1;

    int size_string = strlen(hexa_value);

    for (i = size_string--; i >= 0; i--)
    {
        if (hexa_value[i] >= '0' && hexa_value[i] <= '9')
        {
            decimal_value += (hexa_value[i] - 48) * base;
            base *= 16;
        }
        else if (hexa_value[i] >= 'a' && hexa_value[i] <= 'f')
        {
            decimal_value = (hexa_value[i] - 87) * base;
            base *= 16;
        }
        else if (hexa_value[i] >= 'A' && hexa_value[i] <= 'F')
        {
            decimal_value = (hexa_value[i] - 55) * base;
            base *= 16;
        }
    }
}