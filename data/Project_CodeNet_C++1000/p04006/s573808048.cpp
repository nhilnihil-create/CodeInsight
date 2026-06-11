#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

struct RMQ {
    const ll INF = 1ll<<60;
    int n;
    vector<ll> data;

    RMQ() {}
    RMQ(int n_) { init(n_); }
    RMQ(int n_, vector<ll> &vec) { init(n_); set(vec); build(); }
    void init(int n_) {
        n = 1; while (n < n_) n <<= 1;
        data.assign(n<<1,INF);
    }
    void set(vector<ll> &vec) {
        for (int i = 0; i < (int)vec.size(); i++) data[i+n] = vec[i];
    }
    void build() {
        for (int i = n-1; i > 0; i--) data[i] = min(data[i<<1],data[(i<<1)|1]);
    }

    void update(int i, ll x) {
        i += n; data[i] = x;
        while (i >>= 1) data[i] = min(data[i<<1],data[(i<<1)|1]);
    }
    ll query(int a, int b) {
        ll res = INF;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res,data[l++]);
            if (r & 1) res = min(res,data[--r]);
        }
        return res;
    }
};

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n<<1);
    rep(i,n) { cin >> a[i]; a[i+n] = a[i]; }

    RMQ data(n<<1,a);
    ll ans = 1ll<<60;
    rep(i,n) {
        ll ch = i * x;
        rep(j,n) ch += data.query(n+j-i,n+j+1);
        if (ch < ans) ans = ch;
    }
    cout << ans << endl;
    return 0;
}