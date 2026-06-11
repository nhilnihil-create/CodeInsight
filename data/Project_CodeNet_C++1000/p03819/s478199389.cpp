#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define FORR(i, n) for(ll i = (ll)n - 1LL; i >= 0LL; i--)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template <typename T> using V = vector<T>;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

// 0-indexed, 半開
template <typename T> struct BIT {
  private:
    int n;
    vector<T> dat;

  public:
    BIT(vector<T> v) : n(v.size()) {
        dat.assign(n + 1, 0);
        for(int i = 0; i < n; i++)
            dat[i + 1] = v[i];
        for(int i = 1; i < n; i++)
            if(i + (i & -i) <= n) dat[i + (i & -i)] += dat[i];
    }
    BIT(int n) : n(n) { dat.assign(n + 1, 0); }
    void add(int k, T a) {
        for(k++; k <= n; k += k & -k)
            dat[k] += a;
    }
    // [0,a)
    T sum(int a) {
        T ret = 0;
        for(; a > 0; a -= a & -a)
            ret += dat[a];
        return ret;
    }
    // [a,b)
    T sum(int a, int b) { return sum(b) - sum(a); }
    int lowerBound(T w) {
        if(w <= 0) return 0;
        int x = 0;
        for(int k = 1 << int(log2(n)); k; k /= 2) {
            if(x + k <= n && dat[x + k] < w) {
                x += k;
                w -= dat[x];
            }
        }
        return x + 1;
    }
};

// [l,r)
struct LR {
    int l, r;
    LR(int l, int r) : l(l), r(r) {}
    inline bool operator<(const LR &x) const { return r - l < x.r - x.l; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    V<LR> snuke;
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        snuke.push_back(LR(l, r + 1));
    }
    sort(ALL(snuke));
    BIT<int> bit(m + 1);
    int j = 0;
    FOR(i, 1, m + 1) {
        while(j < n && snuke[j].r - snuke[j].l < i) {
            bit.add(snuke[j].l, 1);
            bit.add(snuke[j].r, -1);
            j++;
        }
        int ans = n - j;
        for(int k = 0; k <= m; k += i)
            ans += bit.sum(k + 1);
        cout << ans << endl;
    }

    return 0;
}