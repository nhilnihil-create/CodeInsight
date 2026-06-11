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

ll inq(ll x, ll y, ll mod)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2, mod);
    if (y % 2) return l * l % mod * x % mod;
    return l * l % mod;
}

ll rev(ll x, ll mod)
{
    return inq(x, mod - 2, mod);
}

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
int a[500000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[n - 1] - a[0] >= 2)
    {
        cout << "No";
        return 0;
    }
    ll x = 0, y = 0;
    int i = 0;
    while (i < n)
    {
        if (a[i] == a[0])
            x++;
        else
            y++;
        i++;
    }
    if (y == 0)
    {
        if (a[0] == n - 1)
        {
            cout << "Yes";
            return 0;
        }
        if (a[0] <= n / 2)
        {
            cout << "Yes";
            return 0;
        }
        cout << "No";
        return 0;
    }
    if (x + 1 <= a[n - 1] && a[n - 1] <= x + y / 2)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
