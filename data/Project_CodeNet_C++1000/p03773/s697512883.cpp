#include<iostream>
#include<cstdio>
using namespace std;
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    printf("%d",(a+b)%24);
    printf("\n");
    return 0;
}