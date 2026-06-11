#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define FILE "file"
#define lc v << 1
#define rc (v << 1) + 1
#define inf 1e+9
#define linf ll(1e+18)
#define classname SubtreeSumHash

const ll mod = 1e+9 + 7;
const int maxn = 1000000 + 5;
ll f[maxn];

void solve()
{
    ll n;
    cin >> n;
    ll s = 0;
    f[1] = n;
    f[2] = n * n;
    for(int i = 3; i <= n; i++)
    {
        if(i > 3)
        {
            s += f[i - 3];
            s %= mod;
        }
        f[i] = f[i - 1] + (n - 1) * (n - 1) + s + (n - i + 2);
        f[i] %= mod;
    }
    cout << f[n] << "\n";
}

void gcj()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0), cout.tie(0);
    //freopen(FILE ".in", "r", stdin);freopen(FILE ".out", "w", stdout);
    //gcj();
    solve();
    return 0;
}
