#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

struct UnionFind
{
    int num;
    vector<int> r, p;
    UnionFind() {}
    UnionFind(int n) : num(n), r(n, 1), p(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x)
    {
        return (x == p[x] ? x : p[x] = find(p[x]));
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    void unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (r[x] < r[y])
            swap(x, y);
        r[x] += r[y];
        p[y] = x;
        num--;
    }
    int size(int x)
    {
        return r[find(x)];
    }
    int count() const
    {
        return num;
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k >> l;
    UnionFind uf1(n);
    rep(i, k)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf1.unite(a, b);
    }
    UnionFind uf2(n);
    rep(i, l)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf2.unite(a, b);
    }
    vector<P> v(n);
    rep(i, n) v[i].first = uf1.find(i);
    rep(i, n) v[i].second = uf2.find(i);
    sort(all(v));
    map<P, int> mp;
    rep(i, n) mp[v[i]]++;
    rep(i, n)
    {
        P p = {uf1.find(i), uf2.find(i)};
        cout << mp[p] << " ";
    }
    cout << endl;
}