#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

ll c[51][51];

void comb_table(int n) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) c[i][j] = 1LL;
            else c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    comb_table(n);
    vll v(n);
    rep(i, n) cin >> v[i];
    sort(v.rbegin(), v.rend());
    double mx = (double)accumulate(v.begin(), v.begin() + a, 0LL) / a;
    int cnt = 0;
    int x = 0;
    rep(i, n) {
        if (v[a-1] == v[i]) {
            cnt++;
            if (x == 0) x = i;
        }
    }
    ll ans = 0;
    if (v[0] == v[a-1]) {
        for (int k = a; k <= b; ++k) {
            ans += c[cnt][k];
        }
    } else {
        ans += c[cnt][a - x];
    }
    cout << fixed << setprecision(10) << mx << endl;
    cout << ans << endl;
}