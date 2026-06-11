#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

template<typename T> T my_gcd(T a, T b) {
    return (a ? my_gcd(b % a, a) : b);
}

template<typename T> T my_lcm(T a, T b){
	return a * b / my_gcd(a, b);	
}

template<typename T> struct UF {
    vector<int> par;
    vector<T> sz;

    UF(int n) {
        par.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_root(int x) {
        return par[x] == x ? x : par[x] = find_root(par[x]);
    }

    bool same(int x, int y) {
        return find_root(x) == find_root(y);
    }

    void unite(int x, int y) {
        x = find_root(x);
        y = find_root(y);
        if (x == y) return;
        
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
    }

    T size_of_tree(int x) {
        return sz[find_root(x)];
    }
};

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    llong n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    rep(k, n) {
        llong lower_limit = a + k * c - (n - k - 1) * d, upper_limit = a + k * d - (n - k - 1) * c;
        if (lower_limit <= b && b <= upper_limit) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}