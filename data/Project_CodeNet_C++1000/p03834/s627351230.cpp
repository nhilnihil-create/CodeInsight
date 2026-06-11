#include <stdio.h>

int main()
{
    char op[19];

    scanf("%s", &op);

    for (int i = 0 ; op[i] != '\0' ; i++){

        if (op[i] != ','){
        printf("%c", op[i]);
        }else {
        printf(" ");
        }


    }

    return 0;
}
