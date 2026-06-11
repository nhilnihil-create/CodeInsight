#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char a[1000],b[1000],c[10000];
    int size=0,sp,i;
    scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&c);
    a[0]=a[0]-32;
    b[0]=b[0]-32;
    c[0]=c[0]-32;
    printf("%c",a[0]);
    printf("%c",b[0]);
    printf("%c",c[0]);

}
