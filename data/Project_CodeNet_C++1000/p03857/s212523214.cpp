#include <cstdio>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <algorithm>
#include <random>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <queue>
#include <functional>
#include <numeric>
#include <chrono>
#include <cstdlib>
using ll = long long;
using namespace std;

const ll MOD = 1e9 + 7;
//const double EPS = 1e(-12);
const double pi = acos(-1);
typedef pair<int, int> P;
#define REP(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EPS 1e-4
#define OUTPUT(i) (cout << (ll)i << endl)
#define ALL(a) ((a).begin(), (a).end())

bool operator<(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
struct UnionFind
{
    vector<int> rnk, par;

    UnionFind(int N) : par(N), rnk(N)
    {
        for (int i = 0; i < N; ++i)
        {
            rnk[i] = 1;
            par[i] = i;
        }
    }
    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
            return;

        if (rnk[x] > rnk[y])
            par[y] = x;
        else
        {
            par[x] = y;
            if (rnk[x] == rnk[y])
                rnk[y]++;
        }
    }
    bool same(int x, int y)
    {
        x = root(x);
        y = root(y);
        return x == y;
    }
};

int ans[200010];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //cout << fixed << setprecision(7);

    int N, K, L;

    cin >> N >> K >> L;

    UnionFind road(N);
    set<pair<int, int>> st;
    for (int i = 0; i < K; ++i)
    {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        road.unite(p, q);
        if (p < q)
            swap(p, q);
        st.insert({p, q});
    }

    UnionFind rail(N);

    for (int i = 0; i < L; ++i)
    {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        rail.unite(r, s);
        if (r < s)
            swap(r, s);
        st.insert({r, s});
    }

    map<pair<int, int>, int> mp;
    for (int i = 0; i < N; ++i)
        mp[make_pair(road.root(i), rail.root(i))]++;

    for (int i = 0; i < N; ++i)
    {
        if (i)
            cout << " ";
        cout << mp[make_pair(road.root(i), rail.root(i))];
    }
    cout << endl;
    return 0;
}