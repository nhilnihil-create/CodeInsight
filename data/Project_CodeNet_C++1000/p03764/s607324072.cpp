#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;


int calc(vector<int> x, int n){
    vector<int> a(n);
    rep(i, 0, n - 1) a[i] = x[i + 1] - x[i];
    // for(int ii = 0; ii < a.size(); ii++){
    //     if(ii) cout << ' ';
    //     cout << a[ii];
    // }
    // cout << endl;
    rep(i, 0, n - 1) x[i] = a[i];
    rep(i, 1, n - 1) a[i] += a[i - 1];
    int now = 0;
    rep(i, 0, n - 1) now += a[i];
    // cout << now << endl;
    int res = now;
    rep(i, 0, n - 2){
        now -= x[i] * (n - 1 - i);
        res += now;
        res %= mod;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, m) cin >> y[i];
    int tmp = calc(x, n);
    int tmp2 = calc(y, m);
    // cout << tmp << " " << tmp2 << endl;
    cout << tmp * tmp2 % mod << endl;
}