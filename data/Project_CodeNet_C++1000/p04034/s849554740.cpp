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
    ll n, m;
    cin >> n >> m;

    vl cnt(n, 1);
    vl v(n);
    v[0] = 1;
    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--;  y--;
        if(v[x]) {
            v[y] = 1;
        }
        cnt[x]--;
        cnt[y]++;
        if(cnt[x] == 0) {
            v[x] = 0;
        }
    }

    ll ans = 0;
    rep(i, n) {
        if(v[i]) {
            ans++;
        }
    }
    
    out(ans);
    re0;
}