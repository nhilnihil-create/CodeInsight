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
    for (ll i = 1; i <= k; ++i) {
        r *= n--;
        r /= i;
    }
    return r;
}

int main()
{
    int n,a,b;
    ll ansc = 0;
    double ansn = 0;
    cin >> n >> a >> b;
    vector<ll> v(n);
    map<ll, ll> m;
    rep0(i, n){
        cin >> v[i];
        ++m[v[i]];
    }
    sort(all(v),greater<>());
    ll min = v[a - 1],cnt = 0;
    rep0(i, a){
        ansn += v[i];
    }
    ansn /= (double)a;
    
    rep0(i, n){
        if(min == v[i])break;
        ++cnt;
    }
    nfor(k, a - 1, b){
        ansc += combinations(m[min], k - cnt + 1);
        if(v[k] != min || v[0] != min)break;
    }
    printf("%.9f\n",ansn);
    pf(ansc)
    return 0;
}
