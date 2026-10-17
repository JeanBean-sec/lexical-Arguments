//TODO
#include <stdio.h>

typedef int Whole;

typedef struct Binrep Binrep;

typedef struct Binrep{
    int dig[100];
}Binrep;

int counter = 0;

int get_bits(Whole number){
    counter = 0; //reinitialize counter
    Binrep rep;
    int *ptr = rep.dig;
    int curr = number;
    int index = 0;
    while (curr != 0){
        *ptr = (int)curr % 2;
        curr = (int)curr / 2;
        ptr++;
        counter++;
        index++;
    }
    return counter;
}

Binrep convert(Whole number){
    counter = 0; //reinitialize counter
    Binrep rep;
    int *ptr = rep.dig;
    int curr = number;
    int index = 0;
    while (curr != 0){
        *ptr = (int)curr % 2;
        curr = (int)curr / 2;
        ptr++;
        counter++;
        index++;
    }
    //populate rest of array with 0 //padding
    while (index < sizeof(rep.dig)/sizeof(int)){
        *ptr = 0;
        ptr++;
        index++;
    }
    return rep;
}

Binrep adder(Binrep *a, Binrep *b){ //add without padding later
    Binrep added;
    int carry;
    //create dig pointers
    int *ptr1 = a->dig;
    int *ptr2 = b->dig;


    int *end1 = ptr1+sizeof(a->dig)/sizeof(int);
    int *end2 = ptr2+sizeof(b->dig)/sizeof(int);//points to end of array (0 padding)

    int *newptr = added.dig; //pointer to start of array
    int *newend = newptr+sizeof(added.dig)/sizeof(int);

    //bin rules
    /*
       1 + 1 = 0, 1
       1 + 0 = 1, 0
       0 + 0 = 0, 0
       1 + 1 + 1 = 1, 1

       1011
       1110

       1. 1, 0
       2. 0, 1
       3. 1, 1
       4. 1, 0
    */

    while(ptr1!=end1){
        if (*ptr1 == 1 && *ptr2 == 1){
            if (carry == 1){
                carry = 1;
                *newptr = 1;
                newptr++;
                ptr1++;
                ptr2++;
                continue;
            }
            carry = 1;
            *newptr = 0;
            newptr++;
            ptr1++;
            ptr2++;
            continue;
        }
        if (*ptr1 == 1 && *ptr2 == 0){
            if (carry == 1){
                carry = 1;
                *newptr = 0;
                newptr++;
                ptr1++;
                ptr2++;
                continue;
            }
            carry = 0;
            *newptr = 1;
            newptr++;
            ptr1++;
            ptr2++;
            continue;
        }
        if (*ptr1 ==0 && *ptr2 == 1){
            if (carry == 1){
                carry = 1;
                *newptr = 0;
                newptr++;
                ptr1++;
                ptr2++;
                continue;
            }
            carry = 0;
            *newptr = 1;
            newptr++;
            ptr1++;
            ptr2++;
            continue;
        }
        if (*ptr1 == 0 && *ptr2 == 0){
            if (carry == 1){
                *newptr = 1;
                carry = 0;
                newptr++;
                ptr1++;
                ptr2++;
                continue;
            }
                *newptr = 0;
                carry = 0;
                newptr++;
                ptr1++;
                ptr2++;
            }
        }
    return added;
    }

//testing happens here //this works! basic conversion
int main(){
    int ex = 237;

    Binrep rep = convert(ex);
    printf("reverse printing (true): ");
    for (int i = sizeof(rep.dig)/sizeof(int)-1; i >= 0; i--){ //reverse printing order
        printf("%d", rep.dig[i]);
    }

    printf("\n");

    printf("forward printing (mag): ");
    for (int i = 0; i < sizeof(rep.dig)/sizeof(int); i++){ //forward printing order
        printf("%d", rep.dig[i]);
    }

    printf("\n");

    printf("reverse printing trunc (true): ");
    for (int i = counter-1; i >= 0; i--){ //reverse printing order trunc
        printf("%d", rep.dig[i]);
    }

    printf("\n");

    printf("forward printing trunc (mag): ");
    for (int i = 0; i < counter; i++){ //forward printing order trunc
        printf("%d", rep.dig[i]);
    }

    Binrep num1 = convert(135);
    Binrep num2 = convert(102);

    //create pointers for reps
    Binrep *num1_ptr = &num1;
    Binrep *num2_ptr = &num2;

    Binrep added = adder(num1_ptr, num2_ptr);

    printf("\n");


    printf("this is 25 or 14 + 11 in bin (true): ");
    for (int i = sizeof(added.dig)/sizeof(int)-1; i >= 0; i--){ //reverse printing order
        printf("%d", added.dig[i]);
    }


    return 0;
}