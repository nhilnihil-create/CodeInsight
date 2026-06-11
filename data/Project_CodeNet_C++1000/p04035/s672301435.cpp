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
#include <tuple>
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
    ll n, L;
    cin >> n >> L;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll maxlen = 0;  // ロープiとロープi+1の長さの合計の最大値
    ll id = -1;  // ロープiとロープi+1の長さの合計が最大となるi
    rep(i, n-1) {
        if(maxlen < a[i] + a[i+1]) {
            maxlen = a[i] + a[i+1];
            id = i+1;
        }
    }

    if(maxlen < L) {
        out("Impossible");
    }
    else {
        out("Possible");
        exrep(i, 1, id-1) {
            out(i);
        }
        for(ll i = n-1; i > id; i--) {
            out(i);
        }
        out(id);
    }

    re0;
}