#include <bits/stdc++.h>
using namespace std;

#define rep(i,s,t) for(ll i = s; i <= t; ++ i)
typedef long long ll;

ll n, e;

int main()
{
    scanf("%lld",&n);
    rep(i,1,n)
        if((1+i)*i/2 >= n)
        {
            e = i;
            break;
        }
    if((e-1)*e/2 == n)
    {
        rep(i,1,e) printf("%lld\n",i);
        return 0;
    }
    rep(i,1,e) if(i != e*(1+e)/2-n) printf("%lld\n",i);
    return 0;
}