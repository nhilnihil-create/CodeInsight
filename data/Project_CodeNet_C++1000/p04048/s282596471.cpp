#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define int long long

typedef long long ll;
typedef long double ld;

const int maxn = 510;
const int mod = 998244353;
const int M = 1e6+10;

ll n, m;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n >> m;
    ll x = __gcd(n,m);
    n = n/x;
    cout<< (3*n-3) * x;
}
