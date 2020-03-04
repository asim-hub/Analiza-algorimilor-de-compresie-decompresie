#include<stdio.h>
#include <stdlib.h>
#include "arithmetic_coding.h"
static int buffer;/*bits input*/
static int bits_to_go;
static int garbage_bits;
start_inputing_bits(){
    bits_to_go=0;
    garbage_bits=0;
}
int input_bit()
{
    int t;
    if(bits_to_go==0){
        buffer=fgetc(stdin);/*citesc urmatorul byte*/
        if(buffer==EOF){
            garbage_bits+=1;
            if(garbage_bits>Code_value_bits-2){
                fprintf(stderr,"Bad input file\n");
                exit(-1);
            }
        }
        bits_to_go = 8;

    }
    t=buffer&1;/*returnez urmatorul bit*/
    buffer >>=1;
    bits_to_go -=1;
    return t;
}