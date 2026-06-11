#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long res, ara[10];
    for(int i=0; i<7; i++)scanf("%lld", &ara[i]);
    if((ara[0]&1ll) && (ara[3]&1ll) && (ara[4]&1ll))
    res= ara[0]+ara[3]+ara[4];
    else if(ara[0] && (ara[3]&1ll) && (ara[4]&1ll))
    res= ara[0]+ara[3]+ara[4]-1;
    else if(ara[3] && (ara[0]&1ll) && (ara[4]&1ll))
    res= ara[0]+ara[3]+ara[4]-1;
    else if(ara[4] && (ara[3]&1ll) && (ara[0]&1ll))
    res= ara[0]+ara[3]+ara[4]-1;
    else res= (ara[0]/2ll)*2ll + (ara[3]/2ll)*2ll + (ara[4]/2ll)*2ll;
    printf("%lld\n", res+ara[1]);
    return 0;
}