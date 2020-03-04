#include "arithmetic_coding.h"
#include "bit_input.c"
#include "bit_output.c"
static void  bit_plus_follow();/*follow*/
static code_value low,high;
static long bits_to_follow;

start_encoding()
{
    low=0;  /*code range*/
    high=Top_value;
    bits_to_follow=0; /*nr de biti*/
}

encode_symbol(symbol,cum_freq)
    int symbol; /*simbolul de codat*/
    int cum_freq[];/*frecventa simbol*/
  { long range;/*dimensiunea regiunii de cod curente*/
    range = (long) (high-low) +1;
    /*interval*/
    high = low+(range*cum_freq[symbol-1])/cum_freq[0]-1;
    low = low+(range*cum_freq[symbol])/cum_freq[0];
    /*output bits*/
    for(;;){
        if(high<Half){/*0, daca e in partea inferioara*/
            bit_plus_follow(0);
        }
        else if(low >= Half){
            bit_plus_follow(1);/*1 , daca e in partea superioara*/
            low-=Half;
            high-=Half;
        }
        else if(low>=First_qtr && high<Third_qtr){
            bits_to_follow+=1;
            low-=First_qtr;
            high-=First_qtr;
        }
        else break;
        low = 2*low;
        high = 2*high+1;
    }
}
/*finaliozarea codificarii sirului de caractere*/
done_encoding()
{
    bits_to_follow +=1;
    if(low<First_qtr) bit_plus_follow(0);
    else bit_plus_follow(1);
}
/*output bits*/
static void bit_plus_follow(bit)
 int bit;
 {  
    output_bit(bit);
    while(bits_to_follow>0){
        output_bit(!bit);
        bits_to_follow-=1;
    }
}