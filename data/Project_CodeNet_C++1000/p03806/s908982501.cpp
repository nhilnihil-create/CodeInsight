//https://atcoder.jp/contests/abc054/tasks/abc054_d

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <limits>
#include <stack>
#include <math.h>
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n) for(ll i=(n)-1; i>=0; --i)
#define SREP(i,s,n) for(ll i=(s), i##_len=(n); i<i##_len; ++i)
#define ALL(v) (v).begin(),(v).end()

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

template<typename T>
struct UnionFind {
    vector<T> par;
    vector<T> rank;
    
    UnionFind(T n = 1) {
        init(n);
    }
    
    void init(T n = 1) {
        par.resize(n); rank.resize(n);
        for (T i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int root(T x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
    
    bool issame(T x, T y) {
        return root(x) == root(y);
    }
    
    bool merge(T x, T y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};


#define INF (ll(1e18))

class SegmentTree {
public:
    int N, n;
    vector<ll> value;
    SegmentTree(int n) {
        this->n = n;
        this->N = 1;
        while (N < n) N *= 2;
        this->value = vector<ll>(2 * N - 1, INF);
    }
    
    void update(int i, ll x) {
        i += N - 1;
        value[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            value[i] = min(value[i * 2 + 1], value[i * 2 + 2]);
        }
    }
    
    ll query(int l, int r) {
        return _query(l, r, 0, 0, N);
    }
    
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b)
            return value[k];
        else {
            ll c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return min(c1, c2);
        }
    }
};

int msb(ll x) {
    int n = 0;
    while (x > 0) {
        x/=2;
        n++;
    }
    return n;
}

#define MOD (1000000007)

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N, Ma, Mb;
    cin >> N >> Ma >> Mb;
    const ll L = 401;
    vector<vector<ll>> dp(L, vector<ll>(L, INF));
    dp[0][0] = 0;
    REP(i, N) {
        ll a, b, c;
        cin >> a >> b >> c;
        RREP(j, L) {
            RREP(k, L) {
                if (j+a < L && k+b < L && dp[j][k] < INF) {
                    dp[j+a][k+b] = min(dp[j+a][k+b], dp[j][k]+c);
                }
            }
        }
    }
    
    ll cost = INF;
    SREP(j, 1, L) {
        SREP(k, 1, L) {
            if (j*Mb == k*Ma) {
                cost = min(cost, dp[j][k]);
            }
        }
    }
    if (cost == INF) cost = -1;
    cout << cost << endl;
}

