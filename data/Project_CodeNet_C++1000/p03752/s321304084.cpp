#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}
const ll INF = 1LL<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll price_min = INF;
    for (int bit = 0; bit < 1<<n; ++bit) {
        if (__builtin_popcount(bit) < k) continue;
        ll price_cur = 0;
        int now_h = 0;
        rep(i, n) {
            if (bit>>i&1) {
                if (a[i] <= now_h) {
                    price_cur += now_h - a[i] + 1;
                    now_h++;
                }
            }
            chmax(now_h, a[i]);
        }
        chmin(price_min, price_cur);
    }
    cout << price_min << endl;
}