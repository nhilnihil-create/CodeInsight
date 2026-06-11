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
const ll MAX = 1e9;
 
int main() {
    ll n;
    cin >> n;

    vl a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    ll m = n*(n+1)/2;
    if(sum%m != 0) {
        out("NO");
        re0;
    }

    ll t = sum/m;  // 操作回数

    vl b(n);
    rep(i, n-1) {
        b[i] = a[i+1] - a[i] - t;
    }
    b[n-1] = a[0] - a[n-1] - t;

    rep(i, n) {
        if(b[i] > 0) {
            out("NO");
            re0;
        }
        if(abs(b[i])%n != 0) {
            out("NO");
            re0;
        }
    }
    
    out("YES");
    re0;
}