#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int d,e;
    d=b-a;
    e=c-b;
    if(d==e)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
