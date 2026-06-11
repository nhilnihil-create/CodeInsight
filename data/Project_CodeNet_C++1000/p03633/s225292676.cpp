#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using PP = pair<ll, pair<ll,ll>>;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

ll gcd(ll a, ll b){
    if (a < b) swap(a,b);

    if (a%b == 0) return b;
    
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

ll n, ans;
ll t[112];

int main() {
    cin >> n;
    rep(i,n) cin >> t[i];
    ans = 1;
    rep(i,n) ans = lcm(ans, t[i]);
    cout << ans << endl;
    return 0;
}