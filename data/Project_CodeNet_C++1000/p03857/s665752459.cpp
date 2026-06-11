#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

struct UnionFind
{
    vector<int> root;
    int n;
    void __init__(int sz)
    {
        n = sz;
        root.resize(n, -1);
    }
    int find(int x)
    {
        if (root[x] >= 0)
        {
            root[x] = find(root[x]);
            return root[x];
        }
        return x;
    }
    void unit(int a, int b)
    {
        int ra, rb;
        ra = find(a);
        rb = find(b);
        if (ra == rb)
        {
            return;
        }
        else if (root[ra] <= root[rb])
        {
            root[ra] += root[rb];
            root[rb] = ra;
        }
        else
        {
            root[rb] += root[ra];
            root[ra] = rb;
        }
        return;
    }
    int count()
    {
        set<int> cnt;
        rep(i, n)
            cnt.insert(find(i));
        return cnt.size();
    }
};

int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    UnionFind road, metro;
    road.__init__(n);
    metro.__init__(n);
    rep(i, k)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        road.unit(x, y);
    }
    rep(i, l)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        metro.unit(x, y);
    }
    map<int, pii> data;
    map<pii, int> cnt;
    rep(i,n){
        int r,m;
        r=road.find(i);
        m=metro.find(i);
        data[i] = mp(r, m);
        cnt[mp(r, m)]++;
    }
    rep(i,n){
        cout << cnt[data[i]] << " ";
    }
    cout << endl;
}