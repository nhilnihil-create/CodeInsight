#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int32_t main() {
    nitin;
    int n,p;
    cin>>n>>p;
    int even=0;
    int odd=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a&1) odd++;
        else even++;
    }
    if(odd>=1)
        cout<<(1LL<<even)*(1LL<<(odd-1));
    else
    {
        if(p==0)
            cout<<(1LL<<even);
        else
            cout<<0<<endl;
    }
    return 0;
}