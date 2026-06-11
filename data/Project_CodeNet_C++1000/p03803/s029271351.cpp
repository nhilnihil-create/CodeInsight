#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    if(a==b) printf("Draw\n");
    else if(a==1) printf("Alice\n");
    else if(b==1) printf("Bob\n");
     else if(a<b) printf("Bob\n");
     else if(a>b) printf("Alice\n");



}
