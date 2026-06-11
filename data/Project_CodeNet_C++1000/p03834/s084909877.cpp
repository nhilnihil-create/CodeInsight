#include<stdio.h>

int main()
{
    char ar[105];
    scanf("%s", ar);
    for(int i = 0; ar[i] != '\0'; i++)
    {
        if(ar[i] == ',')
        {
            printf(" ");
        }
        else
        {
            printf("%c", ar[i]);
        }
    }
    puts("");
    return 0;
}