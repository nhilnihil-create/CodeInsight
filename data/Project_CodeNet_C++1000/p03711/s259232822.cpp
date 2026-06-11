#include<bits/stdc++.h>
#define   ll          long long int
#define   sz          200010
#define   sc(a)       scanf("%lld",&a)
#define   sc2(a,b)    scanf("%lld %lld",&a,&b)
#define   py          printf("Yes\n")
#define   pn          printf("No\n")
using namespace std;


ll num[sz];



int main()
{

    ll a,b;
    ll x,y;

    cin>>a;

    if(a==2)x=3;
    else if(a==4 || a==6 || a==9 || a==11)x=2;
    else
        x=1;

    cin>>a;

    if(a==2)y=3;
    else if(a==4 || a==6 || a==9 || a==11)y=2;
    else
        y=1;

    if(x==y)py;
    else
        pn;


    return 0;
}

