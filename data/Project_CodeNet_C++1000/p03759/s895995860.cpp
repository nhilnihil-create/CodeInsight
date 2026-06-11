#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>

using namespace std;

int main ()
{
    int a,b,c,x,y;
    cin >> a >> b >> c ;
    x=b-a ;
    y=c-b ;

    if((y)==(x))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}