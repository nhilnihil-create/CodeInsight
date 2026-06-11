#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define rnfor(i,a,b) for(ll (i) = (a) - 1; (i) >= (b); --(i))
#define ll long long
#define mod (1000000007)
#define pf(x) cout << (x) << endl
#define all(x) (x).begin(),(x).end()

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);
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
    rep1(i, k)r = r * n-- / i;
    return r;
}

ll a,b;

bool check(ll x, vector<ll>h){
    ll ans = 0;
    rep0(i, h.size()){
        if(h[i] <= x * b)break;
        ans += (h[i] - x * b + a - b - 1) / (a - b);
    }
    if(x >= ans)return true;
    else return false;
}

int main(){
    ll n;
    cin >> n >> a >> b;
    vector<ll> h(n);
    rep0(i, n)cin >> h[i];
    sort(all(h),greater<>());
    ll l = 1,r = 1e9;
    while (l != r) {
        ll x = (l + r) / 2;
        if(check(x, h))r = x;
        else l = x + 1;
    }
    pf(l);
    return 0;
}

