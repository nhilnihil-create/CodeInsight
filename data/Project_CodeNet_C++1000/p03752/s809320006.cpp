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
    ll n, k;
    cin >> n >> k;

    vl base_a(n);
    rep(i, n) {
        cin >> base_a[i];
    }

    if(k == 1) {
        out(0);
        re0;
    }
    
    ll ans = INF;
    rep(b, 1<<n) {
        if(b & 1) {
            continue;
        }
        vl a(n);
        rep(i, n) {
            a[i] = base_a[i];
        }
        ll now = 0;
        ll u = a[0] + 1;  // これまでの最高の高さ + 1
        rep(i, n) {
            if(b & 1<<i) {
                if(u > a[i]) {
                    now += u - a[i];
                    a[i] = u;
                    u++;
                }
                else {
                    u = a[i] + 1;
                }
            }
        }
        ll cnt = 1;
        ll t = a[0];  // これまでの最高の高さ
        exrep(i, 1, n-1) {
            if(t < a[i]) {
                cnt++;
                t = a[i];
            }
        }
        if(cnt >= k) {
            chmin(ans, now);
        }
    }

    out(ans);
    re0;
}