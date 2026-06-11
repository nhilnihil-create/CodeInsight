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

const long long MOD = 998244353;

long long inq(long long x, long long y)
{
    if (y == 0) return 1;
    long long l = inq(x, y / 2);
    if (y % 2) return l * l % MOD * x % MOD;
    return l * l % MOD;
}

int n, l, t, a, b;
vector<int> x;
long long times = 0;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (b == 1) a += t;
        else a -= t;
        long long L = -1e9, R = 1e9;
        while (L + 1 < R)
        {
            long long mid = (L + R) / 2;
            if (mid * l <= a) L = mid;
            else R = mid;
        }
        times += L;
        a = (a % l + l) % l;
        x.push_back(a);
    }
    sort(all(x));
    times = (times % n + n) % n;
    for (int i = times; i < x.size(); i++) cout << x[i] << "\n";
    for (int i = 0; i < times; i++) cout << x[i] << "\n";
}
