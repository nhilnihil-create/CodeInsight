#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

struct lazyRMQ {
    const ll INF = 1ll<<60;
    int n;
    vector<ll> data, lazy;

    lazyRMQ() {}
    lazyRMQ(int n_) { init(n_); }
    lazyRMQ(int n_, vector<ll> &vec) { init(n_); set(vec); build(); }
    void init(int n_) {
        n = 1; while (n < n_) n <<= 1;
        data.assign(n<<1,INF);
        lazy.assign(n<<1,INF);
    }
    void set(vector<ll> &vec) {
        for (int i = 0; i < (int)vec.size(); i++) data[i+n] = vec[i];
    }
    void build() {
        for (int i = n-1; i > 0; i--) data[i] = min(data[i<<1],data[(i<<1)|1]);
    }

    void eval(int k) {
        if (lazy[k] = INF) return;
        data[k] = min(data[k],lazy[k]);
        if (k < n) {
            lazy[(k<<1)|0] = min(lazy[(k<<1)|0],lazy[k]);
            lazy[(k<<1)|1] = min(lazy[(k<<1)|1],lazy[k]);
        }
        lazy[k] = INF;
    }
    void update(int a, int b, ll x, int k = 1, int l = 0, int r = 0) {
        if (r == 0) r = n;
        eval(k);
        if (r <= a || b <= l) return;
        else if (a <= l && r <= b) { lazy[k] = x; eval(k); }
        else {
            update(a, b, x, (k<<1)|0, l, (l+r)/2);
            update(a, b, x, (k<<1)|1, (l+r)/2, r);
            data[k] = min(data[k<<1],data[(k<<1)|1]);
        }
    }
    ll query(int a, int b, int k = 1, int l = 0, int r = 0){
        if (r == 0) r = n;
        if (r <= a || b <= l) return INF;
        eval(k);
        if (a <= l && r <= b) return data[k];
        else {
            ll vl = query(a, b, (k<<1)|0, l, (l+r)/2);
            ll vr = query(a, b, (k<<1)|1, (l+r)/2, r);
            return min(vl,vr);
        }
    }
};

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n<<1);
    rep(i,n) { cin >> a[i]; a[i+n] = a[i]; }

    lazyRMQ data(n<<1,a);
    ll ans = 1ll<<60;
    rep(i,n) {
        ll ch = i * x;
        rep(j,n) ch += data.query(n+j-i,n+j+1);
        if (ch < ans) ans = ch;
    }
    cout << ans << endl;
    return 0;
}