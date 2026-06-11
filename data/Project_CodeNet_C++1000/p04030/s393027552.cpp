/*  ex9_1
    Graku   */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

typedef struct stack {
    int size;
    int count;
    char data[SIZE];
    char *top;
} stack;

void initialize_stack(stack *stk);
char pop(stack *stk);
void push(stack *stk, char c);
void print_stack(stack *stk);

int main(void) {
    stack stk;
    initialize_stack(&stk);

    char s[SIZE];
    scanf("%s", s);

    for (int i = 0; i < (int)strlen(s); ++i) {
        if (s[i] == 'B') { //delete a element
            if (stk.count > 0) { //stk has elements
                pop(&stk);
            }
        }
        else {
            push(&stk, s[i]); //add a element to stk
        }
    }

    print_stack(&stk);

    return 0;
}

void initialize_stack(stack *stk) {
    stk->size = SIZE;
    stk->count = 0;
    stk->top = stk->data; //stk.data[0] is always empty
}

char pop(stack *stk) {
    char c;
    if (stk->count <= 0) { //stk has no elements
        printf("Error: stack underflow.\n");
        exit(1);
    }
    c = *(stk->top);
    stk->top--;
    stk->count--;
    return c;
}

void push(stack *stk, char c) {
    if (stk->count >= stk->size) { //stk has biggest elements it can have
        printf("Error: stack overflow.\n");
        exit(1);
    }
    *(++stk->top) = c;
    stk->count++;
}

void print_stack(stack *stk) {
    char *p = stk->data;
    for (int i = 0; i < stk->count; ++i) {
        printf("%c", p[i+1]); //stk.data[0] is always empty
    }
    printf("\n");
}