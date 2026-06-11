#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rfor(i,a,b) for(ll (i) = (a); (i) > (b); --(i))
#define ll long long
#define mod (1000000007)
#define pf(a) cout << (a) << endl;
#define all(x) (x).begin(),(x).end()

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll factorial(ll n){
    ll t = 1;
    rep1(i, n)t *= i;
    return t;
}

ll combinations(ll n, ll k) {
    ll r = 1;
    for (ll d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

int main()
{
    ll n,t,maxd = 0,ans = 0;
    cin >> n >> t;
    vector<ll> a(n),Min(n + 1);
    Min[0] = 1e9 + 1;
    rep0(i, n){
        cin >> a[i];
        Min[i + 1] = min(a[i],Min[i]);
        maxd = max(a[i] - Min[i],maxd);
    }
    rep0(i, n)if(a[i] - Min[i] == maxd)++ans;
    pf(ans)
    return 0;
}
