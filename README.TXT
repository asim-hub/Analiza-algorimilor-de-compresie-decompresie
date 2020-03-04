ASIMIONESEI DANIEL 321 CD
 In arhiva am atasat cei doi algoritmi pentru compresie si decompresie:
1)HUFFMAN(algo1.cpp)
Aici se gaseste atat algoritmul de comprimare cat si algoritmul de decomprimare
al fisierului de intrare, respectiv al fisierului binar.
Makefile-ul contine o regula de compilare in urma careia rezulta un executabil
algo1.Acest executabil va avea ca prim argument fisierul de intrare,unde se va gasi
textul ce urmeaza sa fie comprimat(ex: ./algo1 test$in.txt).In functia main se va apela
functia buildTree, care va avea ca argument textul.In functia buildTree voi construi un
arbore pentru codificarea fiecarui de caracter plecand de la o coada de prioritati.
Fiecare caracter va fi inlocuit cu un codul specific ,iar sucesinea de coduri va fi
scrisa in fisierul binar("outcomprim.bin") cu functia writeBinary.
Decompresia acestui fisier se va face cu functia decode, iar rezultatul
va fi scris in fisierul "outdecompri.txt".

2)Arithmetic Coding(algo2dencode.c si algo2encode.c)
Pentru ralizarea acestui algoritm am plecat de la un program principal caruia i-am adaugat
fisierele header necesare.
Pentru comprimarea fisierului test:
-encode.c -> MAIN PROGRAM FOR ENCODING
-model.h ->MAIN PROGRAM FOR ENCODING AND DECODING
-arithmetic_encodin.c ->ARITHMETIC ENCODING ALGORITHM
-adaptive_model.c -> ADAPTIVE SOURCE MODEL
Pentru decomprimarea fisierului binar:
-decode.c -> MAIN PROGRAM FOR DECODING
-arithmetic_decode.c ->ARITHMETIC DECODING ALGORITHM
-model.h
-adaptive_model.c

Pe langa acestea:
-arithmetic_coding.h ->DECLARATION USED FOR ARITHMETIC ENCODING AND DECODING
-bit_input.c , bit_output.c -> BIT INPUT/OUTPUT ROUTINES

Compilarea fisierului algo2encode.c va realiza un fisier executabil algo2encode
care se va rula astfel: ./algo2encode test$in.txt >outcomprim.bin, unde primul argument
este fisierul de intrate , iar output-ul programului va fi redirectat intr-un fisier
binar.
Compilarea fisierului algo2decode.c va realiza un fisier executabil elgo2decode
care se va rula astfel: ./algo2decode outdecomprim.txt <outcomprim.bin, unde primul argument
este fisierul in care se va realiza decomprimarea fisierului binar redirectat din linia de comanda.
Iar fisierul binar este cel care a fost comprimat anterior.
In fisierul in se vor gasi setul de teste variate in functie de frecventa caracterelor si diversitatea lor.
In Makefile se gasesc regulile de compilare pentru a obtine fisierele executanile si regula de clean.
Am ales sa implementez cei doi algoritmi in limbaje diferinte(C si C++) pentru usurinta scrierii codului.
In rezolvarea temei am preluat secvente de cod de la urmatoarele surse:
https://github.com/SiwonP/huffman_C
https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
https://www.techiedelight.com/huffman-coding/
https://github.com/nayuki/Reference-arithmetic-coding/tree/master/cpp







