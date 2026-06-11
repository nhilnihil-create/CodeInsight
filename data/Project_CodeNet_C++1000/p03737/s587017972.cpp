#include<iostream>
#include<cstring>
#include<cstdio>
int main()
{
    char a[10],b[10],c[10];
    scanf("%s %s %s",a,b,c);
    printf("%c%c%C\n",toupper(a[0]),toupper(b[0]),toupper(c[0]));
    return 0;

}
