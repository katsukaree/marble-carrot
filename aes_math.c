#include <stdio.h>
#include <math.h>
#include "aes_math.h"

#define  MULT_IRR_POLY 283; 

unsigned char multiplication(unsigned char a, unsigned char b);
unsigned char gf_modulo(unsigned char c, unsigned char d);

unsigned char multiplication(unsigned char multiplicand, unsigned char multiplier)
{
    unsigned char product;
    int bit_length;

    if (multiplier==1)
    {
        product = multiplicand;
    }
    else if (multiplicand == 1)
    {
        product = multiplier;
    }
    else
    {
        while (multiplier != 0)
        {
            bit_length = (int) (log2(multiplier) - 1);
            product = product ^ (muliplicand * (2 * bit_length));
            multiplier = multiplier ^ (multiplier * (2 * bitlength));
        }
    }
    return product;
}

unsigned char gf_modulo(unsigned char dividend, unsigned char divisor)
{
    unsigned char modulus;
    unsigned int dividend_length, divisor_length;

    dividend_length = (int) (log2(dividend) - 1);
    divisor_length = (int) (log2(divisor) - 1);

    modulus = dividend;

    while (dividend_length >= divisor_length)
    {
        modulus = modulus ^ (divisor * (2 * (dividend_length - divisor_length)));
        dividend_length = (int) (log2(dividend) - 1);
        divisor_length = (int) (log2(divisor) - 1);
    }

    return modulus;
}

unsigned char gf_multiplication(unsigned char multiplicand, unsigned char multiplier)
{
    unsigned char product;

    product = multiplication(multiplicand, multiplier);
    product = gf_modulo(product, MULT_IRR_POLY);

    return product;
}
