//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;

int64_t gcd(int64_t a, int64_t b) {return b?gcd(b, a%b):a;}
int64_t lcm(int64_t a, int64_t b) {return a/gcd(a,b)*b;}
int64_t extgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) { // ax+by=gcd(a, b)の解を与える
    int64_t d = a;
    if(b) {
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

int main() {
    int n;
    cin >> n;
    vector<ll> t(n);
    rep(i, n) {
        cin >> t[i];
    }

    ll ans = 1;
    rep(i, n) {
        ans = lcm(ans, t[i]);
    }

    cout << ans << endl;
}