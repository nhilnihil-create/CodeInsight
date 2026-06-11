#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//-------------------------------------

struct UnionFind
{
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x)
    {
        return -par[root(x)];
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind uf_tetudou(n);
    UnionFind uf_douro(n);
    for (int i = 0; i < k; i++)
    {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        uf_douro.merge(p, q);
    }
    for (int i = 0; i < l; i++)
    {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        uf_tetudou.merge(r, s);
    }

    vector<pair<ll, ll>> p(n);
    map<pair<ll, ll>, int> ans;
    for (ll i = 0; i < n; i++)
    {
        p[i].first = uf_douro.root(i);
        p[i].second = uf_tetudou.root(i);
        ans[p[i]]++;
    }

    for (ll i = 0; i < n; i++)
    {
        cout << ans[p[i]] << " ";
    }
    cout << endl;
}