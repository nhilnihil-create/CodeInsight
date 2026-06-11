#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll n, K;
    cin >> n >> K;

    vl a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    
    ll ans = 0;
    rep(i, n) {
        ll lim = K;
        bool ok = true;
        rep(j, 31) {
            if(!(lim & 1<<j) && (a[i] & 1<<j)) {
                ok = false;
            }
        }
        if(ok) {
            ans += b[i];
        }
    }

    for(ll d = 30; d >= 0; d--) {
        ll mask = 1<<d;
        ll lim = K;
        if(K & mask) {
            lim &= ~mask;
            lim |= (mask - 1);
            ll now = 0;
            rep(i, n) {
                bool ok = true;
                rep(j, 31) {
                    if(!(lim & 1<<j) && (a[i] & 1<<j)) {
                        ok = false;
                    }
                }
                if(ok) {
                    now += b[i];
                }
            }
            chmax(ans, now);
        }
    }
    
    out(ans);
    re0;
}