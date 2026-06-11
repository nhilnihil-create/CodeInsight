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

int nextInt()
{
    int y = 0;
    char c = getchar();
    while ('0' <= c && c <= '9')
    {
        y = 10 * y + c - '0';
        c = getchar();
    }
    return y;
}

long long max(long long a, long long b)
{
    if (a > b) return a;
    return b;
}

long long min(long long a, long long b)
{
    if (a < b) return a;
    return b;
}

int n;
int pos[5101];
int res[3000000];

signed main()
{
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pos[i + 1];
    set<pair<int, int> > ss;
    for (int i = 1; i <= n; i++)
    {
        ss.insert({pos[i], i - 1});
        res[pos[i]] = i;
    }
    for (int i = 1; i <= n * n; i++)
    {
        auto it = ss.begin();
        if (res[i] == 0)
        {
            pair<int, int> r = *it;
            while (r.second == 0)
            {
                ss.erase(r);
                if (ss.size() == 0)
                {
                    cout << "No";
                    return 0;
                }
                it = ss.begin();
                r = *it;
            }
            if (r.first > n * n) res[i] = r.first - n * n;
            else res[i] = res[r.first];
            ss.erase(it);
            r.second--;
            ss.insert(r);
        }
        else
        {
            int t = 1;
            for (auto it : ss)
            {
                if (it.first == i)
                {
                    if (it.second > 0) t = 0;
                }
            }
            if (!t)
            {
                cout << "No";
                return 0;
            }
            pair<int, int> v = {n * n + res[i], n - res[i]};
            ss.insert(v);
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n * n; i++)
    {
        cout << res[i] << " ";
    }
}
