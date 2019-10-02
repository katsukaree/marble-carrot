#include <stdio.h>
#include <stlib.h>

#define   BLOCKSIZE 128
#define   KEYLENGTH 128
#define   ROUNDS    10

int main(int argc, char *argv[]) {
    char buffer[16];
    char state[4][4];

    FILE *input_file = fopen(argv[1], "rb");
    
    if (fp == NULL) {
        fprintf(stderr, "cannot open input file\n");
        return 1;
    }
 
    return 0;
   
}
