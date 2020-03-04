#include<stdio.h>
static int buffer; /*bits buffered*/
static int bits_to_go;/*nr de biti liberi in buffer*/
start_outputing_bits(){
    buffer=0; /*bufer gol la inceput*/
    bits_to_go=8;
}
output_bit(bit)
int bit;
{   //FILE* file = fopen("out1.bin","wb");
    buffer>>=1;/*pun bit in vraful buffer-ului*/
    if(bit) buffer|=0x80;
    bits_to_go-=1;
    if(bits_to_go==0){  /*cand se umple buffer-ul afisez ce este in el*/
    putc(buffer,stdout);
        bits_to_go=8;
    }
    //fclose(file);
}
done_outputing_bits()
{
    putc(buffer>>bits_to_go,stdout);
}