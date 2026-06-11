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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;

ll min(ll a, ll b) {return a < b ? a : b;}
//ll min(int a, ll b) {return a < b ? a : b;}
//ll min(ll a, int b) {return a < b ? a : b;}
//ll min(int a, int b) {return a < b ? a : b;}

ll max(ll a, ll b) {return a > b ? a : b;}
//ll max(int a, ll b) {return a > b ? a : b;}
//ll max(ll a, int b) {return a > b ? a : b;}
//ll max(int a, int b) {return a > b ? a : b;}

namespace MySpace{

};

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

const long long INF = 1e18;
#define int long long

int n, m, d;
int a[2000][2000];
string s = "RYBG";

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    int n0 = n, m0 = m;
    n = 1000, m = 1000;
    if (d % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[i][j] = (i + j) % 2;
            }
        }
    }
    else
    {
        int st = 1;
        int K = 0;
        for (int i = 0; i < n; i += 2)
        {
            int p = st;
            int k = K;
            int x = i;
            for (int j = 0; j < m && x >= 0; j++, x--)
            {
                if (p == 0)
                {
                    p = d / 2;
                    k = 3 - k;
                }
                a[x][j] = k;
                p--;
            }
            st++;
            if (st == d / 2 + 1) st = 1, K ^= 1;
        }
        st = 1;
        K = 0;
        for (int i = 1; i < n; i += 2)
        {
            int p = st;
            int k = K;
            int x = i;
            for (int j = 0; j < m && x >= 0; j++, x--)
            {
                if (p == 0)
                {
                    p = d / 2;
                    k = 3 - k;
                }
                a[x][j] = k;
                p--;
            }
            st++;
            if (st == d / 2 + 1) st = 1, K ^= 1;
        }
    }
    for (int i = 0; i < n0; i++)
    {
        for (int j = 0; j < m0; j++)
        {
            cout << s[a[i][j]];
        }
        cout << "\n";
    }
}
