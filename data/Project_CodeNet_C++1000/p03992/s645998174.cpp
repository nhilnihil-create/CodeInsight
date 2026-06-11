#include<cstdio>
int main()
{
    char s[20];
    scanf("%s", s + 1);
    for(int i = 1; i <= 12; i++)
    {
        putchar(s[i]);
        if(i == 4)
            putchar(' ');
    }
    putchar('\n');
    return 0;
}