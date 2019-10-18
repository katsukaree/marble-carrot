#include <stdio.h>
#include <math.h>
#include "aes_math.h"

#define  MULT_IRR_POLY 283; 

unsigned char multiplication(unsigned char multiplicand, unsigned char multiplier)
{
    unsigned char product;
    int bit_length;

    if (multiplier==1)
    {
        product = multiplicand;
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
}
