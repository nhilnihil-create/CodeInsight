#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
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
const double pi = acos(-1);

int main() {
    ll n;
    cin >> n;

    ll k = 0;  // 木の直径
    vl v(n);  // v[i] : iの個数
    rep(i, n) {
        ll a;
        cin >> a;
        v[a]++;
        chmax(k, a);
    }

    bool ok = true;
    if(k%2 == 0) {
        v[k/2]--;
        exrep(i, k/2 + 1, k) {
            v[i] -= 2;
        }
        rep(i, n) {
            if(v[i] < 0) {
                ok = false;
            }
        }
        for(ll i = k/2; i >= 1; i--) {
            if(v[i] > 0) {
                ok = false;
            }
        }
    }
    else {
        exrep(i, k/2 + 1, k) {
            v[i] -= 2;
        }
        rep(i, n) {
            if(v[i] < 0) {
                ok = false;
            }
        }
        for(ll i = k/2 + 1; i >= 1; i--) {
            if(v[i] > 0) {
                ok = false;
            }
        }
    }

    if(ok) {
        out("Possible");
    }
    else {
        out("Impossible");
    }
    
    re0;
}