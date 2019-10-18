#include <stdio.h>
#include <math.h>

int main(int argc, int argv[]) {
	unsigned char multiplier, multiplicand, product;
	unsigned int bit_length, mod_bit_length, mods_bit_length, irr_polynomial;

	product = 0;
	multiplier = 0x57;
	multiplicand = 0x83;
	irr_polynomial = 283;

	while (multiplier != 0) {
		bit_length = (int) (log2(multiplier) - 1);
		product = product ^ (multiplicand * (2 * bit_length));
		multiplier = multiplier ^ (multiplier * (2 * bit_length));
	}

	mod_bit_length = (int) (log2(product) - 1);
	mods_bit_length = (int) (log2(irr_polynomial) - 1);
	while (mod_bit_length >= mods_bit_length) {
		product = product ^ (irr_polynomial * (2 * (mod_bit_length - mods_bit_length)));
		mod_bit_length = (int) (log2(product) -1);
		mods_bit_length = (int) (log2(irr_polynomial) - 1);
	}

	printf("0x%x", product);
	return 0;
}
