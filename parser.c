// welcome to LexicalArguments!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "token.h"
#include "node.h"


Node BindWeight(Node *node, Token *curr);


Tree Populate(Token *curr, Tree *tree){
    Tree AST;
    Node *node_ptr = tree->nodes; //puts pointer to the start, every call
    while (*curr->text!='\0'){
        *node_ptr->Text = *curr->text;
        //bind weight to node
        *node_ptr = BindWeight(node_ptr, curr);
        node_ptr++; //move to next node box

        //move to next token (token cleaning will be after)
        curr++;
    }
    return AST;
}

Node BindWeight(Node *node, Token *curr){
    if (curr->type == identi){
        if (curr->text == "int"){
            node->weight = IDENT;
            return *node;
        }
    if (curr->type == number){
        node->weight = NUMBER;
        return *node;

        }
    if (curr->type == termina){
        node->weight = TERMINA;
        return *node;

    }
    if (curr->type == opera){
        if (curr->text == "+"){
            node->weight = ADD;
            return *node;

        }
        if (curr->text == "-"){
            node->weight = SUBTRACT;
            return *node;

        }
        if (curr->text == "*"){
            node->weight = MULTIPLY;
            return *node;

        }
        if (curr->text == "/"){
            node->weight = DIVIDE;
            return *node;
        }
    }
    }
}


// terminal loop
int main()
{
    char input[100] = "";

    // while(true){
    //     printf(">> ");
    //     fflush(stdout);

    //     if (fgets(input, sizeof(input), stdin) == NULL) break;

    //     input[strcspn(input, "\n")] = '\0';

    //     if (strcmp(input, "exit") == 0){
    //         break;
    //     }
    // }

    while (1)
    {

        printf(">>: ");

        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "\n") == 0)
        {
            continue;
        }
        else if (strcmp(input, "\n") == 1)
        {
            if (strcmp(input, "exit\n") == 0 ||
                     strcmp(input, "quit\n") == 0)
            {
                printf("Goodbye!");
                break;
            }

            else if (strcmp(input, "help\n") == 0)
            {
                printf("exit - gets you out.\n");
                printf("quit - gets you out.\n");
                continue;
            }
            else{
                printf("No. enter 'help' if you're confused.\n");
            }
            continue;
        }
    }
    return 0;
}

/*
Planned syntactic features:

highly translated human language

parsing engine: pratt parsing


*/