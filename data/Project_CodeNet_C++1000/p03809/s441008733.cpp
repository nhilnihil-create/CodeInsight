#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <unordered_map>
#include <unordered_set>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

using std::min;
using std::max;

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

inline int nextInt()
{
    int x = 0;
    char c = getchar();
    int mi = (c == '-');
    if (c == '-') c = getchar();
    while ('0' <= c && c <= '9')
    {
        x = 10 * x + c - '0';
        c = getchar();
    }
    if (mi) return x * -1;
    return x;
}

int n;
ll a[500000];
vector<int> graph[500000];
ll mark[500000];

ll dfs(int v)
{
    mark[v] = 1;
    ll leaf = 0;
    int t = 0;
    ll max_leaf = 0;
    for (auto u : graph[v])
    {
        if (mark[u] == 0)
        {
            ll x = dfs(u);
            leaf += x;
            max_leaf = max(max_leaf, x);
            t = 1;
        }
    }
    if (t == 0)
    {
        return a[v];
    }
    if (leaf < a[v])
    {
        cout << "NO";
        exit(0);
    }
    long long r = leaf - a[v];
    long long up = leaf - 2 * r;
    if (up < 0)
    {
        cout << "NO";
        exit(0);
    }
    if (max_leaf * 2 > leaf + up)
    {
        cout << "NO";
        exit(0);
    }
    return up;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 2)
    {
        if (a[1] == a[2])
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    int v = 0;
    for (int i = 1; i <= n; i++) if (graph[i].size() > 1) v = i;
    if (dfs(v) == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
