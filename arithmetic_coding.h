#define Code_value_bits 16  /*numa de biti*/
typedef long code_value;    /*type code value*/
#define Top_value (((long)1<<Code_value_bits)-1)/*lungime code value*/
#define First_qtr (Top_value/4+1)
#define Half (2*First_qtr)
#define Third_qtr (3*First_qtr)