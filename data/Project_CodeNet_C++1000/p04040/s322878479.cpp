#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7ll ;

long long modpower(long long a , long long b)
{
    if(b == 0)
        return 1ll ;
    long long x = modpower(a , b / 2ll) ;
    x = (x * x) % mod ;
    if(b & 1)
        return (x * a) % mod ;
    return (x % mod) ;
}

struct combination
{
    vector<long long>fact , inv ;
    combination(int sz) : fact(sz + 1) , inv(sz + 1)
    {
        fact[0] = 1ll ;
        inv[0] = 1ll ;
        for(long long i = 1 ; i <= sz ; ++i)
        {
            fact[i] = (fact[i-1] * i) % mod ;
            inv[i] = modpower(fact[i] , mod - 2ll) ;
        }
    }
    long long choose(int n , int k) const
    {
        if(k < 0 || n < k)
            return 0 ;
        return ((((fact[n] * inv[k]) % mod) * inv[n - k]) % mod) ;
    }
};

combination comb(2e5+2) ;

int main()
{
    int n , m , a , b;
    cin>>n>>m>>a>>b ;
    int nowx = n-a ;
    long long sum = 0ll ;
    long long ans = 0ll ;
    for(int i = b+1 ; i <= m ; ++i)
    {
        long long x = (comb.choose(nowx-1ll + i-1ll , i-1ll))%mod ;
        long long y = (comb.choose(n-nowx-1+m-i , m-i)) % mod ;
        ans = (ans + ((x * y) % mod)) % mod ;
        ans = (ans % mod) ;
    }
    return cout<<ans<<"\n" , 0 ;
}
