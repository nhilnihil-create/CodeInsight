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

const int N = 325501;
const int MOD = 1e9 + 7;

int n;
long long a[N];

void pt(int x)
{
    if (x) cout << "First";
    else cout << "Second";
    exit(0);
}

void solve(int k)
{
    long long s = 0, cnt = 0, kek = 0;
    for (int i = 0; i < n; i++)
    {
        s += (a[i] - 1);
        cnt += a[i] % 2;
        kek += a[i] == 1;
    }
    //cout << s << endl;
    if (s % 2 == 1)
    {
        pt(k);
    }
    if (cnt > 1)
    {
        pt(1 ^ k);
    }
    if (cnt == 0)
        exit(75);
    if (cnt == 1 && kek == 1) pt(1 ^ k);
    int g = 0;
    for (int i = 0; i < n; i++)
    {
    	if (a[i] % 2) a[i]--;
    	g = std::__gcd(g, a[i]);
    }
    for (int i = 0; i < n; i++) a[i] /= g;
    k ^= 1;
    solve(k);
}

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
    solve(1);
}
