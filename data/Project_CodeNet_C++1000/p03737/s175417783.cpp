#include<stdio.h>
#include<ctype.h>
int main()
{
    int i;
    char s1[1000],s2[1000],s3[1000],a[3];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
       a[0]=toupper(s1[0]);
       a[1]=toupper(s2[0]);
       a[2]=toupper(s3[0]);
       a[3]='\0';
    printf("%s",a);
    
    
}