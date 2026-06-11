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
using std::min;
using std::max;
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

ll n, m;
ll a[1500000];
vector<ll> open[1500000];
vector<ll> close[1500000];
ll ans = 0;
ll optimize = 0;

int cld(int x, int y)
{
    if (x <= y) return y - x;
    else return m - x + y;
}

signed main()
{
    srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        ans += cld(a[i - 1], a[i]);
        if (a[i - 1] < a[i])
        {
            open[a[i - 1] + 1].push_back(0);
            close[a[i]].push_back(cld(a[i - 1], a[i]) - 1);
            
            open[a[i - 1] + 1 + m].push_back(0);
            close[a[i] + m].push_back(cld(a[i - 1], a[i]) - 1);
        }
        else
        {
            open[a[i - 1] + 1].push_back(0);
            close[a[i] + m].push_back(cld(a[i - 1], a[i]) - 1);
            
            open[a[i - 1] + 1 + m].push_back(0);
        }
    }
    ll cur = 0, elems = 0;
    for (int i = 1; i <= 2 * m; i++)
    {
        for (int j = 0; j < open[i].size(); j++)
        {
            cur += open[i][j];
            elems++;
        }
        optimize = max(optimize, cur);
        //cout << ans - cur << " " << i << "\n";
        for (int j = 0; j < close[i].size(); j++)
        {
            cur -= close[i][j];
            elems--;
        }
        cur += elems;
    }
    //cout << "\n";
    cout << ans - optimize;
}
