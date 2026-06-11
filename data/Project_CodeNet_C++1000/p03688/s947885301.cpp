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

    ll ma = 0;
    ll mi = n;
    vl a(n);
    rep(i, n) {
        cin >> a[i];
        chmax(ma, a[i]);
        chmin(mi, a[i]);
    }

    if(ma - mi >= 2) {
        out("No");
        re0;
    }

    if(ma == mi) {
        if(ma == n-1) {
            out("Yes");
        }
        else if(2*ma <= n) {
            out("Yes");
        }
        else {
            out("No");
        }
        re0;
    }

    // 以下、ma - mi = 1
    ll cntmi = 0;
    rep(i, n) {
        if(a[i] == mi) {
            cntmi++;
        }
    }
    
    if(cntmi < ma && 2*(ma - cntmi) <= n - cntmi) {
        out("Yes");
    }
    else {
        out("No");
    }

    re0;
}