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
    ll n;
    cin >> n;

    vl p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }

    vl b(n);
    b[n-1] = 1;
    for(ll i = n-2; i >= 0; i--) {
        b[i] = 3*(n-1-i)*10000;
    }

    vl c(n);
    ll ma = 1e9;
    for(ll i = n-1; i >= 0; i--) {
        c[p[i]] = ma;
        ma--;
    }

    vl a(n);
    rep(i, n) {
        a[i] = c[i] - b[i];
    }

    rep(i, n) {
        cout << a[i];
        if(i < n-1) {
            cout << " ";
        }
    }
    cout << "\n";
    
    rep(i, n) {
        cout << b[i];
        if(i < n-1) {
            cout << " ";
        }
    }
    cout << "\n";
    
    re0;
}