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
#define NAME ""

const int INF = 1e9;
const long long INFLL = 1e18;

string s;
int dp[500000];
int nxt[26][500000];
int fxd[26];
int ok[500000];

signed main()
{
    if (NAME != "") { freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout); }
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> s;
    s = " " + s;
    fill(dp, dp + s.size() + 1, INF);
    for (int i = 0; i < 26; i++) fxd[i] = s.size();
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++) nxt[j][i] = fxd[j];
        if (i) fxd[s[i] - 'a'] = i;
    }
    dp[0] = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            dp[nxt[j][i]] = min(dp[nxt[j][i]], dp[i] + 1);
        }
    }
    ok[s.size()] = 1;
    //cout << dp[s.size()] << endl;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (ok[nxt[j][i]] && dp[i] + 1 == dp[nxt[j][i]])
            {
                ok[i] = 1;
            }
        }
    }
    for (int i = 0; i < s.size(); )
    {
        for (int j = 0; j < 26; j++)
        {
            if (ok[nxt[j][i]] && dp[i] + 1 == dp[nxt[j][i]])
            {
                cout << (char)(j + 'a');
                i = nxt[j][i];
                break;
            }
        }
    }
}
