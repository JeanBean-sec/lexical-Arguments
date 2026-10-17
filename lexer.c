#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

int main(){
    Token stack[100]; //todo dynamic alloc 

    char string[] = ("int this fucking d\" 1 : {sucks;s} ");

    char *ptr = string;
    Token *stack_ptr = stack;
    char *new = stack_ptr->text;

    int count = 0;
    
    while(*ptr != '\0'){ //DONT CHANGE THIS BLOCK 
        printf("%c", *ptr);
        if (isspace(*ptr)){
            if (*(ptr+1)=='\0'){
                break;
            }
            else{
            ptr++;
            continue;
        }
        if (*ptr == '='){
            stack_ptr++;
            new = stack_ptr->text;
            *new = *ptr;
            ptr++;
            new++;
            count++;
            continue;
        }
        }
        if (ispunct(*ptr)){
            stack_ptr++;
            new = stack_ptr->text;
            *new = *ptr;
            ptr++;
            new++;
            count++;
            continue;
        }

        if (isdigit(*ptr)){
            if (*(ptr-1) == ' '){
                stack_ptr++;
                count++;
                new = stack_ptr->text;
                *new = *ptr;
                ptr++;
                new++;
                *new = '\0';
                continue;
            }
            else if (*(ptr-1)=='='){
                stack_ptr++;
                count++;
                new = stack_ptr->text;
                *new = *ptr;
                ptr++;
                new++;
                *new = '\0';
                continue;
            }
            else{
                *new = *ptr; //* has values
                ptr++;
                new++;
            }
        }
        // // if (*ptr == '.'){
        // //     count++;
        // //     *new = '\0';
        // //     *(stack_ptr)++;
        // //     new = stack_ptr->text;
        // //     new = ptr;
        // //     *(ptr)++;
        // //     (new)++;
            
        // }
        if (isalpha(*ptr)){
            if (*(ptr-1) == ' '){
                //move to new stack pointer
                stack_ptr++;
                count++;
                new = stack_ptr->text;


                //populate stack and move internal pointer
                *new = *ptr;
                ptr++;
                new++;
                *new = '\0';
                

                continue;
            }
            else if (!isalpha(*(ptr-1)) || *(ptr+1) == '\n'){
                //move to new stack pointer
                stack_ptr++;
                count++;
                new = stack_ptr->text;


                //populate stack and move internal pointer
                *new = *ptr;
                ptr++;
                new++;
                *new = '\0';
                

                continue;  
            }
            else{
                *new = *ptr; //* has values
                ptr++;
                new++;
            }
        }
        *new = '\0';
}
    printf("\n\n");

    for (int i = 0; i<=count; i++){
        if (strlen(stack[i].text)>1){
            if (isalpha((stack[i].text[0]))){
                stack[i].type = identi;
                printf("%s:%d\n", stack[i].text, stack[i].type);
            }
            else if(isdigit((stack[i].text[0]))){
                stack[i].type = number;
                printf("%s:%d\n", stack[i].text, stack[i].type);
            }
        }
        else if (strlen(stack[i].text)==1){
                if (isalpha((stack[i].text[0]))){
                    stack[i].type = identi;
                    printf("%c:%d\n", stack[i].text[0], stack[i].type);
                }
                else if(ispunct(stack[i].text[0])){
                    stack[i].type = opera;
                    printf("%c:%d \n", stack[i].text[0], stack[i].type);
                }
                else if(isdigit(stack[i].text[0])){
                    stack[i].type = number;
                    printf("%c:%d \n", stack[i].text[0], stack[i].type);
                }
                else if(stack[i].text[0] == '.'){
                    stack[i].type = termina;
                    printf("%c:%d \n", stack[i].text[0], stack[i].type);
                }
                }
}

    printf("\n");

    printf("%c:%d \n", stack[9].text[0], stack[9].type);

    printf("total number of tokens: %d\n", count);


    // *new = '\0';

    // printf("%s\n", toke.text);
    // printf("%d\n", toke.type);

    return 0;
}

// previous code 

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