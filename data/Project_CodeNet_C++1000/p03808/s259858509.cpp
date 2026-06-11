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

#define int unsigned long long

typedef unsigned long long ll;
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
ll dif[500000];
ll st[500000];
ll b[500000];
ll phi[500000];
ll s, op;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) s += a[i];
    for (int i = 0; i < n; i++) dif[i] = a[i] - a[(i - 1 + n) % n];
    for (int i = 1; i <= n; i++) op += i;
    op = s / op;
    for (int i = 0; i < n; i++)
    {
        ll cnt = (op - dif[i]) / n;
        st[i] += cnt;
        st[i + n] += -cnt;
        phi[i + n] += -cnt * n;
    }
    ll counter = 0, progressions = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        progressions += st[i];
        counter += progressions + phi[i];
        b[i] = counter;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] + b[i + n] != a[i])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
