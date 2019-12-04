#include <stdio.h>
#include <math.h>
#include "aes_math.h"

#define  MULT_IRR_POLY 283 

unsigned int multiplication(unsigned char multiplicand, unsigned char multiplier)
{
    unsigned int product, bit_length, intermediate;

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
	product = 0;
	while (multiplier != 0)
        {
            bit_length = (int) (log2(multiplier) + 1);
	    intermediate = multiplicand << (bit_length - 1);
	    product = product ^ (intermediate);
            multiplier = multiplier ^ (1 << bit_length - 1);
        }
    }
    return product;
}

unsigned char gf_modulo(unsigned int dividend, unsigned int divisor)
{
    unsigned int dividend_length, divisor_length;

    dividend_length = (int) (log2(dividend) + 1);
    divisor_length = (int) (log2(divisor) + 1);

    while (dividend_length >= divisor_length)
    {
	dividend = dividend ^ (divisor << (dividend_length - divisor_length));
        dividend_length = (int) (log2(dividend) + 1);
        divisor_length = (int) (log2(divisor) + 1);
    }

    return dividend;
}

unsigned char gf_multiplication(unsigned char multiplicand, unsigned char multiplier)
{
    unsigned int product;

    product = multiplication(multiplicand, multiplier);
    product = gf_modulo(product, (unsigned int) MULT_IRR_POLY);

    return product;
}

unsigned char division(unsigned int dividend, unsigned int divisor)
{
    quotient = 0;

    dividend_length = (int) (log2(dividend) + 1);
    divisor_length = (int) (log2(divisor) + 1);

    return quotient;
}
