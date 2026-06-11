#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return (x * 1ll * y) % MOD;
}

lld binpow(lld x, lld y)
{
    lld z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

lld inv(lld x)
{
    return binpow(x, MOD - 2);
}

lld divide(lld x, lld y)
{
    return mul(x, inv(y));
}

// Combinations

/*
lld fact[N];

void precalc()
{
    fact[0] = 1;
    for(lld i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

lld C(lld n, lld k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;
    while(t--)
    {
        lld n,a ,b;
        cin>>n>>a>>b;
        string str;
        cin>>str;
        lld ctr=0,ctr2=0;
        for(i=0;i<str.length();i++)
        {
            if(str[i]=='a' && ctr+ctr2<(a+b))
            {
                cout<<"Yes"<<endl;
                ctr++;
            }
            else
            if(str[i]=='b' && ctr+ctr2<(a+b) && ctr2<b)
            {
                cout<<"Yes"<<endl;
                ctr2++;
            }
            else
                cout<<"No"<<endl;
        }
    }
}

