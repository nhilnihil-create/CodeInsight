#include<bits/stdc++.h>
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define printd(x) printf("%.12f\n", ans);
#define print(x) cout << (x) << endl;
#define Yes() cout << "Yes" << endl;
#define No() cout << "No" << endl;
#define YES() cout << "YES" << endl;
#define NO() cout << "NO" << endl;
#define printa(x, n) for(ll i = 0; i < n; i++) {cout << (x[i]) << " ";} cout << endl;
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;


vector<vector<bool>> vvi(15, vector<bool>(15, false));

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> ok(n * m + 1, false);

    if (k % n == 0 || k % m == 0) {
        Yes();
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            ok[i * (n - j) + (m - i) * j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ok[i * (m - j) + (n - i) * j] = true;
        }
    }
    cout << (ok[k] ? "Yes" : "No") << endl;
    return 0;
}
