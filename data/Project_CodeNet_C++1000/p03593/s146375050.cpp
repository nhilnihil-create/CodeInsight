#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main()
{
    ll H, W;
    cin >> H >> W;
    map<char, ll> m;
    REP(i, H) {
        string str;
        cin >> str;
        REP(j, W) {
            m[str[j]]++;
        }
    }
    ll cnt4 = 0;
    for(P p : m) {
        cnt4 += p.second / 4;
        p.second %= 4;
    }
    if (H > 1 && W > 1 && cnt4 < ((H / 2) * (W / 2))) {
        PRINT("No");
        return 0;
    }
    if (H % 2 == 0 && W % 2 == 0 && cnt4 == H*W/4) {
        PRINT("Yes");
        return 0;
    }
    ll odd = 0;
    for(P p : m) {
        odd += p.second % 2;
    }
    if (H % 2 == 1 && W % 2 == 1) {
        if (odd == 1) {
            PRINT("Yes");
        } else {
            PRINT("No");
        }
    } else {
        if (odd == 0) {
            PRINT("Yes");
        } else {
            PRINT("No");
        }
    }
    return 0;
}
