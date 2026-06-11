#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a>0 && b>=a)puts("Positive");
    else if(a<=0 && b>=0)puts("Zero");
    else if(b<0 && a<=b)
    {
        if( (b-a+1)%2 )puts("Negative");///number within that range is ODD
        else puts("Positive");
    }
    return 0;
}
