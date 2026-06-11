#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a=b-a;
    c=c-b;
    if(a==c){
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}
