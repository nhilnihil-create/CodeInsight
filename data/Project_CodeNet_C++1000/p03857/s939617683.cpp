#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int gmax_n = 200005;

int fa[gmax_n * 2];
int Dep[gmax_n * 2];

void init(int n)
{
    rep(i, 1, n)
    {
        fa[i] = i;
        Dep[i] = 0;
    }
}

int find(int x)
{
    if(fa[x] == x) return x;
   	return fa[x] = find(fa[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(Dep[x] < Dep[y]) fa[x] = y;
    else
    {
        fa[y] = x;
        if(Dep[x] == Dep[y]) Dep[x] ++;
    }
}

bool same(int x, int y)
{
    return find(x) == find(y);
}

int main()
{
    int n, k, l;
    cin >> n >> k >> l;

    init(n * 2);
    rep(i, 1, k)
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    rep(i, 1, l)
    {
        int a, b;
        cin >> a >> b;
        unite(a + n, b + n);
    }

    pair<int, int> p[gmax_n];
    map<pair<int, int>, int> m;
    rep(i, 1, n) p[i] = mp(find(i), find(i + n));
    rep(i, 1, n) m[p[i]] ++;
    rep(i, 1, n) cout << m[p[i]] << " ";
    return 0;
}
