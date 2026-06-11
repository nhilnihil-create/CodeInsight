#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,w,a,b,fakt[1000000],rez,mod=1000000007;

ll step(ll a,ll b)
{
    if(b==0)
        return 1;
    else
    {
        ll p=step(a,b/2)%mod;
        if(b%2==0)
            return (p*p)%mod;
        else
            return (((p*p)%mod)*a)%mod;
    }
}

ll inverse(ll n)
{
    return step(n,mod-2)%mod;
}

ll binomni(ll n,ll k)
{
    return (( ( fakt[n]*inverse(fakt[k]) )%mod * inverse(fakt[n-k]) )%mod );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>h>>w>>a>>b;
    //a=h-a+1;
    fakt[0]=1;
    for(ll i=1;i<1000000;i++)
    {
        fakt[i]=fakt[i-1]*i;
        fakt[i]%=mod;
    }

    for(ll i=1;i<=h-a;i++)
    {
        rez+=binomni(b+i-2,b-1)*binomni(h+w-b-1-i,h-i);
        rez%=mod;
    }

    cout<<rez<<endl;

    return 0;
}
/*
100000 100000 44444 55555

738162020
*/
