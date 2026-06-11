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

    vvl v(m+1);  // v[i] : xの中でmで割った余りがiのものの集合
    rep(i, n) {
        ll x;
        cin >> x;
        v[x%m].pb(x);
    }

    exrep(i, 0, m/2) {
        if(v[i].size() < v[m-i].size()) {
            swap(v[i], v[m-i]);
        }
    }

    ll ans = v[0].size()/2;
    exrep(i, 1, m/2) {
        if(m%2 == 0 && i == m/2) {
            ans += v[m/2].size()/2;
            break;
        }
        ll S = v[i].size();
        ll T = v[m-i].size();
        ll U = S - T;
        ans += T;
        map<ll, ll> mp;
        for(auto p : v[i]) {
            mp[p]++;
        }
        ll cnt = 0;
        for(auto p : mp) {
            ll nokori = U - 2*cnt;
            if(p.second <= nokori) {
                cnt += p.second/2;
            }
            else {
                cnt += nokori/2;
            }
        }
        ans += cnt;
    }

    out(ans);
    re0;
}