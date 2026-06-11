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
#include <random>
#include <functional>

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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
ll min(int a, ll b) {return a < b ? a : b;}
ll min(ll a, int b) {return a < b ? a : b;}
ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
ll max(int a, ll b) {return a > b ? a : b;}
ll max(ll a, int b) {return a > b ? a : b;}
ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()
#define int long long
#define NAME ""

long long n, m, h, w;
long long a[1000][1000];
long long summ;

long long f(int i, int j)
{
    return j == m ? 0 : a[i][j] + f(i, j + 1);
}

int p()
{
    cout << "Yes\n";
    for (int i = 0, j; i < n; puts(""), i++)
        for (j = 0; j < m; cout << " ", j++)
            cout << a[i][j];
    exit(0);
}

signed main()
{
    if (NAME != "")
    {
        freopen(NAME ".in", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> m >> h >> w;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = 1;
    for (int i = h - 1; i < n; i += h) for (int j = w - 1; j < m; j += w) a[i][j] = - (w * h);
    if (n % h == 0 && m % w == 0) puts("No"), exit(0);
    if (h == 1) for (int i = 0; i < n; i = i < n - 1 ? i + 1 : i + p()) for (int j = 0; j < m; j++) a[i][j] = (j % w == w - 1) ? (1 - w) * 250001 - 1 : 250001;
    if (w == 1) for (int j = 0; j < m; j = j < m - 1 ? j + 1 : j + p()) for (int i = 0; i < n; i++) a[i][j] = (i % h == h - 1) ? (1 - h) * 250001 - 1 : 250001;
    long long INF1 = 990000000 / (h - 1), INF2 = 990000000 / (w - 1);
    INF1 *= (h - 1), INF2 *= (w - 1);
    if (n % h != 0) for (int i = 0; i < n; i++) a[i][m - 1] = INF1 / (h - 1);
    if (n % h != 0) for (int i = h - 1; i < n; i += h) a[i][m - 1] = -INF1 - 250001;
    if (m % w != 0) for (int j = 0; j < m; j++) a[n - 1][j] = INF2 / (w - 1);
    if (m % w != 0) for (int j = w - 1; j < m; j += w) a[n - 1][j] = -INF2 - 250001;
    if (n % h != 0 && m % w != 0) a[n - 1][m - 1] = max(INF1 / (h - 1), INF2 / (w - 1));
    p();
}
