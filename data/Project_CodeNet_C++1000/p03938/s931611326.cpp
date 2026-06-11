//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];

    vi a(n, 1), b(n, 1);
    int h = n-1;
    rep(i, n) {
        int now = p[i];
        now--;
        if(now != n-1) a[now+1] += h;
        if(now) b[now-1] += h;
        h--;
    }
    rep(i, n-1) {
        a[i+1] += a[i];
        b[n-i-2] += b[n-i-1];
    }

    rep(i, n) {
        cout << a[i] << (i == n-1?'\n':' ');
    }
    rep(i, n) {
        cout << b[i] << (i == n-1?'\n':' ');
    }
}