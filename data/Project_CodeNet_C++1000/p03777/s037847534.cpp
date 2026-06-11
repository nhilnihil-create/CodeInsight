#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    char a,b;
    scanf("%c %c",&a,&b);
    if(a=='H') printf("%c\n",b);
    else if(a=='D')
    {
        if(b=='H') printf("D\n");
        else printf("H\n");
    }
    return 0;
}
