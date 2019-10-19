#include <stdio.h>
#include <stdlib.h>
#include "aes_math.h"

#define   BLOCKSIZE 128
#define   KEYLENGTH 128
#define   ROUNDS    10

int main(int argc, char *argv[]) {
    unsigned char *buffer;

    // Check for input and key file arguments
    if (argc != 3) 
    {
    	fprintf(stderr, "Usage: ./aes.out INPUT_FILE KEY_FILE\n");
    	return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *key_file = fopen(argv[2], "rb");   

    // Check for input file. If not, throw error
    if (!input_file) 
    {
        fprintf(stderr, "Cannot find input file %s\n", argv[1]);
        return 1;
    }

    // Check for key file. If not, throw error
    if (!key_file)
    {
        fprintf(stderr, "Cannot find key file %s\n", argv[2]);
        return 1;
    }

    // Read input file into buffer
    fseek(input_file, 0, SEEK_END);
    unsigned long file_len = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    buffer=(char *)malloc(file_len+1);

    if (!buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(input_file);
        return 1;
    }
    
    fread(buffer, file_len, 1, input_file);
    fclose(input_file);

    // Move input into state
    unsigned char state[4][4];
    int i, j;
    int k = 0;
     
    for (i=0; i<4; i++)
    {
        j=0;
        for (j=0; j<4; j++)
        {
            state[j][i] = buffer[k];
            k++;
        }
    }

    unsigned char product = gf_multiplication(87, 19);
    printf("0x%x\n", product);

    return 0;   
}
