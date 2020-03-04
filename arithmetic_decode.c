#include "arithmetic_coding.h"
#include "bit_input.c"
#include "bit_output.c"
static code_value value;/*valoare cod*/
static code_value low,high;/*sfarsitul regiunii de cod curent*/
start_decoding(){
    int i;
    value =0;   /*input bits*/
    for(int i=1;i<=Code_value_bits;i++){
        value=2*value+input_bit();
    }
    low=0;
    high = Top_value;
}
/*decodarea urmatorului simbol*/
int decode_symbol(cum_freq,filename)
    int cum_freq[];/*frecventa*/
    char * filename;
    {long range;/*size code*/
    int cum;
    int symbol;/*simbol decodat*/
    range = (long)(high-low)+1;
    cum=(((long)(value-low)+1)*cum_freq[0]-1)/range; /*frecventa*/
    for(symbol=1;cum_freq[symbol]>cum;symbol++);
    /*interval*/
    high=low+(range*cum_freq[symbol-1])/cum_freq[0]-1;
    low=low+(range*cum_freq[symbol])/cum_freq[0];
    /*extrag biti si modific intervalele*/
    for(;;){
        if(high<Half){
            /*nothing*/
        }
        else if(low>=Half){
            value-=Half;
            low-=Half;
            high-=Half;
        }
        else if(low >= First_qtr && high<Third_qtr){
            value-=First_qtr;
            low-=First_qtr;
            high-=First_qtr;
        }
        else break;
        low=2*low;
        high=2*high+1;
        value=2*value+input_bit(filename);
    }
    return symbol;
}