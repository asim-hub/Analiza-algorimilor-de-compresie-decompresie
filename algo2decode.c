#include<stdio.h>
#include<stdlib.h>
#include"model.h"
#include "arithmetic_decode.c"
#include "adaptive_model.c"
int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "wb");
    start_model();
    start_inputing_bits();
    start_decoding();
    for(;;){
        int ch;
        int symbol;
        symbol=decode_symbol(cum_freq,argv[1]);/*decodarea urmatorului simbol*/
        if(symbol==EOF_symbol) break;
        ch=index_to_char[symbol];/*convertesc in caracter*/
        fputc(ch,file);/*scriu caracterul*/
        update_model(symbol);
    }
    exit(0);
}