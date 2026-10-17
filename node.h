#ifndef NODE_AST
#define NODE_AST

typedef enum {
    MULTIPLY,
    DIVIDE,
    ADD,
    SUBTRACT,
    EQUAL,
    NOT_EQUAL,
    NUMBER,
    IDENT,
    TERMINA,
} Weight;


typedef struct Node {
    Weight weight;
    char Text[32];

    struct Node *prev;
    struct Node *forward;
} Node;

typedef struct Tree{
    Node nodes[100]; //arbitrary size
    Node *root;
    Node *current;
} Tree;

#endif