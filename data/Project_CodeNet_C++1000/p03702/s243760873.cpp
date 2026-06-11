// All Heil Fire Lord Zuko

#include<bits/stdc++.h>
using namespace std ;

#define sz(x) (int)x.size()
#define F first
#define S second
#define PB push_back

#define debug(x) cerr << #x << " = " << x << "\n"

typedef long long ll ;
typedef pair<ll, ll> pll ;
typedef pair<ll, bool> pllb ;

const ll N = 100 * 1000 + 19 ;
const ll Mod = 998244353 ;
const ll inf = 1e10 + 19 ;

ll n, a, b, h[N];

ll BinarySearch() ;
bool IsValid(ll x) ;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0) ;
    cin >> n >> a >> b ;
    for (int i = 0 ; i < n ; i ++) cin >> h[i] ;
    cout << BinarySearch() ;
    return 0 ;
}

ll BinarySearch() {
    ll low = 0, high = inf ;
    while (high - low > 1) {
        ll mid = (low + high) / 2 ;
        if (IsValid(mid))
            high = mid ;
        else
            low = mid ;
    }
    return high ;
}

bool IsValid(ll x) {
    ll cnt = 0 ;
    for (int i = 0 ; i < n ; i ++) {
        ll tmp = h[i] ;
        tmp -= x * b ;
        if (tmp <= 0) continue ;
        cnt += (tmp / (a - b)) + min(1ll , tmp % (a - b)) ;
    }
    return cnt <= x ;
}

/* THINGS TO CHECK */

// Runtime ->
// Overflow ->
// Time ->
// Memory ->

/* READ PROBLEM STATEMENT CAREFULLY */
