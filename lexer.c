#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int main(){
    Token stack[100]; //todo dynamic alloc 

    char string[] = "44 aa";

    char *ptr = string;
    Token *stack_ptr = stack;
    char *new = stack_ptr->text;

    int count = 1;
    
    while(*ptr != '\0'){
        printf("%c", *ptr);
        if (isspace(*ptr)){
            count++;
            *new = '\0'; //clean the first token before moving to the next token
            *(stack_ptr)++; //go to next empty stack element
            *(ptr)++;
            *(new)++;
            new = stack_ptr->text;
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
        else if (isdigit(*ptr)){
            *new = '\0';
            *new = *ptr;
            *(ptr)++;
            *(new)++;
            continue;
        }
        else if (*ptr == '.'){
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
            *new = '\0';
            *new = *ptr;
            *(ptr)++;
            *(new)++;
            continue;
        }
}
    printf("\n\n");

    for (int i = 0; i<count; i++){
        if (strlen((stack[i].text))>1){
            stack[i].type = identi;
            printf("%s:%d\n", stack[i].text, stack[i].type);
        }
        else if (strlen((stack[i].text))==1){
                if (isalpha((stack[i].text[0]))){
                    stack[i].type = identi;
                    printf("%c:%d\n", stack[i].text[0], stack[i].type);
                    continue;
                }
                else if(ispunct(stack[i].text[0])){
                    stack[i].type = opera;
                    printf("%s:%d \n", stack[i].text, stack[i].type);
                    continue;
                }
                else if(isdigit(stack[i].text[0])){
                    stack[i].type = number;
                    printf("%s:%d \n", stack[i].text, stack[i].type);
                    continue;
                }
                else if(stack[i].text[0] == '.'){
                    stack[i].type = termina;
                    printf("%s:%d \n", stack[i].text, stack[i].type);
                }
                }
}

    printf("\n");

    printf("%s:%d\n", stack[1].text, stack[1].type);
    printf("total number of tokens: %d\n", count);


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