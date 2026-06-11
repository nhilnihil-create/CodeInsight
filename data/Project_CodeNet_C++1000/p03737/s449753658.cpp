#include<stdio.h>
#include<string.h>
#define N 10

int main()
{
    char s1[10],s2[10],s3[10];
    scanf("%s%s%s", s1,s2,s3);
    char dif = 'A'-'a';

    printf("%c%c%c",s1[0]+dif,s2[0]+dif,s3[0]+dif);
    return 0;
}
