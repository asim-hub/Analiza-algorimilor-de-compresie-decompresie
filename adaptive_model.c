#include "model.h"
int freq[No_of_symbols+1];/*symbol frequencies*/
start_model()
{
    int i;
    for(i=0;i<No_of_chars;i++){/*setare tabela*/
        char_to_index[i]=i+1;
        index_to_char[i+1]=i;
    }
    for(i=0;i<=No_of_symbols;i++){/*setare frecvente*/
        freq[i]=1;
        cum_freq[i]=No_of_symbols-i;
    }
    freq[0]=0;
}
update_model(symbol)
int symbol; /*index-ul unui nou simbol*/
{
    int i;/*index nou*/
    if(cum_freq[0]==Max_frequency){/*vrific daca frecventa este cat maix*/
        int cum;
        cum=0;
        for(i=No_of_symbols;i>=0;i--){
            freq[i]=(freq[i]+1)/2;
            cum_freq[i]=cum;
            cum+=freq[i];
        }
    }
    for(i=symbol;freq[i]==freq[i-1];i--);/*caut un nou index*/
    if(i<symbol){
        int ch_i,ch_symbol;
        ch_i=index_to_char[i];/*update tabel*/
        ch_symbol=index_to_char[symbol];
        index_to_char[i]=ch_symbol;
        index_to_char[symbol]=ch_i;
        char_to_index[ch_i]=symbol;
        char_to_index[ch_symbol]=i;
    }
    freq[i]+=1;/*incrementez frecventa*/
    while(i>0){
        i-=1;
        cum_freq[i]+=1;
    }
}