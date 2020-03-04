#include<stdio.h>
#include<stdlib.h>
#include "model.h"
#include "arithmetic_encode.c"
#include "adaptive_model.c"
main(int argc, char *argv[])
{
    start_model();
    start_outputing_bits();
    start_encoding();
    FILE *file = fopen(argv[1], "r");
    for(;;){
        int ch;
        int symbol;
        ch=fgetc(file);/*citesc urmatorul char*/
        if(ch==EOF) break;
        symbol = char_to_index[ch];/*transform in index*/
        encode_symbol(symbol,cum_freq);/*codez simbolul*/
        update_model(symbol);
    }
    encode_symbol(EOF_symbol,cum_freq);/*codez EOF simbol*/
    done_encoding();/*setez ultimi biti*/
    done_outputing_bits();
    exit(0);
}