/* ex 9_1
series2 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
//条件　文字列を格納するスタックを定義、push,pop
typedef struct stack {
    int size;
    int count;        //現在格納されている文字数
    char data[SIZE];  //データ内容そのもの
    char *top;  //外部からのアクセス部はdata配列の一番後ろの番地のアドレスをさす
} stack;

void init_stack(stack *stk) {
    stk->count = 0;
    stk->size = SIZE;
    stk->top = &(stk->data[SIZE]);
}
void push(stack *stk, char data) {
    if (stk->count <
        stk->size) {  //用意したstackの要領未満の時、入力文字をトップアドレスに追加する
        stk->top--;
        *(stk->top) = data;
        stk->count++;
    }
}
char pop(stack *stk) {
    char latest;
    if (stk->count > 0) {  //文字が残っている時
        latest = *(stk->top);
        stk->top++;
        stk->count--;
        return latest;
    } else {
        latest = '\0';  //文字が残っていない時null文字を返す
    }
    return latest;
}

// stackなので、再帰的に呼び出すことで正しい順にする。(直接呼び出すのは、stackとしての設計に反する)
void printout(stack *stk) {
    char out = pop(stk);
    if (out) {  // outがnull文字でない時
        printout(stk);
        printf("%c", out);
    }
}

int main(void) {
    stack stk;
    init_stack(&stk);
    char inp = ' ';
    while (inp != '\n') {
        scanf("%c", &inp);
        if (inp == 'B') {
            pop(&stk);
        } else if (inp != '\n') {
            push(&stk, inp);
        }
    }
    printout(&stk);
    printf("\n");

    return 0;
}