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
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

//Range Minimum Query
struct segment {
    int n;
    vector<int64_t> dat;
    // n_は範囲
    segment(int n_) { // nはn_以上の2^?
        n = 1<<(32-__builtin_clz(n_));
        if(n == 2*n_) n >>= 1;
        dat.assign(2*n-1, INT64_MAX);
    }
    //初期化(初期状態はINT64_MAX)
    void init(vector<int64_t> &vec) {
        int num = vec.size();
        rep(i, num) {
            dat[i+n-1] = vec[i];
        }
        rep(i, n-1) {
        dat[n-2-i] = min(dat[n*2-3-i*2], dat[n*2-2-i*2]);
        }
    }
    // k番目の値をaに変更
    void update(int k, int64_t a) {
        // 葉の節点
        k += n-1;
        dat[k] = a;
        // 登りながら更新
        while(k>0) {
            k = (k-1)/2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }
    // [a, b)の最小値
    int64_t query(int a, int b) {
        return query_(a, b, 0, 0, n);
    }
    //kは節点の番号, [l, r)に節点が対応
    // (a, b, 0, 0, .n)で呼ぶ
    int64_t query_(int a, int b, int k, int l, int r) {
        if(a>=r || l>=b) return INT64_MAX;
        if(a<=l && r<=b) return dat[k];
        else {
            int chl = k*2+1;
            int chr = k*2+2;
            int64_t vl = query_(a, b, chl, l, (l+r)/2);
            int64_t vr = query_(a, b, chr, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    segment seg(n);
    seg.init(a);

    ll ans = LINF;
    rep(i, n) {
        ll now = i*x;
        ll n_;
        rep(j, n) {
            if(j < i) {
                n_ = min(seg.query(0, j+1), seg.query((j-i+n)%n, n));
            } else {
                n_ = seg.query(j-i, j+1);
            }
            now += n_;
        }
        ans = min(ans, now);
    }

    cout << ans << endl;
}