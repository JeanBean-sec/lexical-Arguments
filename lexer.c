#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
we identify tokens by their type, and we store the text.
we go through the string character by character, and we keep track of the current token.
*/

enum TokenType{
    eof =0,
    ident=1,
    number=2,
    op=3, 
};

typedef struct{
    enum TokenType type;
    char text[32];
} Token;


int main(){
    Token stack[100];

    char string[] = "Hello World! fuck";

    char *ptr = string;
    Token *stack_ptr = stack;
    char *new = stack_ptr->text;

    int count = 1;
    
    while(*ptr != '\0'){
        printf("%c", *ptr);
        if (isspace(*ptr)){
            *new = '\0'; //clean the first token before moving to the next token
            *(stack_ptr)++; //go to next empty stack element
            *(ptr)++;
            *(new)++;
            new = stack_ptr->text;
            count++;
            *new = *ptr;
            continue;
        }
        else if (ispunct(*ptr)){
            count++;
            *new = '\0';
            *(stack_ptr)++;
            new = stack_ptr->text;
            *new = *ptr;
            *(ptr)++;
            *(new)++;
            continue;
        }
        else if (isalpha(*ptr)){
        *new = *ptr;
        *(ptr)++;
        *(new)++;
        }
        *new = '\0';
}
    printf("\n\n");

    for (int i = 0; i<count; i++){
        if (strlen((stack[i].text))>1){
            stack[i].type = ident;
            printf("%s: %d\n", stack[i].text, stack[i].type);
        }
        if(ispunct(stack[i].text[0])){
            stack[i].type = op;
            printf("%s:%d \n", stack[i].text, stack[i].type);
    }}


    printf("this is '%s'\n", stack[3].text);

    printf("this is the lenght of '%s': %d\n",stack[3].text, strlen(stack[3].text));
    

    printf("%d\n", count);


    // *new = '\0';

    // printf("%s\n", toke.text);
    // printf("%d\n", toke.type);

    return 0;
}


// typedef enum{
//     eof,
//     ident,
//     number,
//     op,
// } tokentype;

// struct token{
//     tokentype type;
//     char text[32];
// };

// int main(){
//     const char *input[10]; //we can just reuse this once we've hit a terminating token.

//     input[0] = "int";
//     input[1] = "sam";
//     input[2] = ".";

//     struct token tok;

//     if (input[0] == "int"){
//         strcpy(tok.type, "int");
//         strcpy(tok.name, "sam");
//         if (input[2] == "."){
//             tok.value = NULL;
//         }
//     }
   
//     char *tokens[] = {""};

//     char input2[] = "int sam.";

//     char space[sizeof(input2)];

//     for (int i = 0; input2[i]!='.' ; i++){
//         space[i] = input2[i];
//     }

//     char *token = strtok(input2, " ");
//     tokens[0] = token;
    
//     while (token!=NULL){
//         printf("%s\n", token);
//         token = strtok(NULL, " ");
//     }

//     // for (int i = 0; space[i]!='.'; i++){
//     //     printf("%c\n", space[i]);
//     // }



//     printf("%s\n", tokens[0]);
//     printf("%s\n", token);


//     printf("%c\n", space[1]);
//     printf("%s\n", tok.type);
//     printf("%s\n", tok.name);

//     printf("%s\n", tok.value);

//     return 0;
// }

// /*
// uninitialized variable assignment 1st;
// "int sam."
// */