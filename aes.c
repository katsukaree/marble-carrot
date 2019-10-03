#include <stdio.h>
#include <stdlib.h>

#define   BLOCKSIZE 128
#define   KEYLENGTH 128
#define   ROUNDS    10

int main(int argc, char *argv[]) {
    unsigned char *buffer;
    FILE *input_file = fopen(argv[1], "rb");
    
    // Check for file. If not, throw error
    if (!input_file) {
        fprintf(stderr, "cannot open input file\n");
        return 1;
    }

    // Read file into buffer
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

    return 0;   
}
