#ifndef TOKEN
#define TOKEN

/*
we identify tokens by their type, and we store the text.
we go through the string character by character, and we keep track of the current token.
*/

enum TokenType{
    termina =0,
    identi=1,
    number=2,
    opera=3, 
};

typedef struct{
    enum TokenType type;
    char text[32];
} Token;


#endif