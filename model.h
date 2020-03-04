#define No_of_chars 256 /*numarul de caractere simbol*/
#define EOF_symbol (No_of_chars+1)/*index of EOF symbol*/
#define No_of_symbols (No_of_chars+1)/*numarul total de simboluri*/
/*tabela de trecere dintre caracter si simbol index*/
int char_to_index[No_of_chars];/*char->index*/
unsigned char index_to_char[No_of_symbols+1];/*index->char*/
#define Max_frequency 16383/*frecventa maxima*/
int cum_freq[No_of_symbols+1];
