#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <numeric>
#include <functional>
#include <cmath>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int mod = 1000000007;
const ll MOD = 1000000007;
const ll INF = 1LL << 60;
#define PI (acos(-1))

struct BIT
{
    int n;
    vector<int> bit;
    BIT()
    {
        init();
    }
    BIT(int n) : n(n)
    {
        init();
    }
    void init()
    {
        bit.clear();
        bit.resize(n + 1, 0);
    }
    int sum(int i)
    {
        int s = 0;
        while (i > 0)
        {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    int sum(int x, int y)
    {
        return sum(y) - sum(x - 1);
    }
    void add(int i, int x)
    {
        while (i <= n)
        {
            bit[i] += x;
            i += i & -i;
        }
    }
    int lower_bound(int w)
    {
        if (w <= 0)
            return 0;
        int x = 0, r = 1;
        while (r < n)
            r <<= 1;
        for (int k = r; k > 0; k >>= 1)
        {
            if (x + k <= n && bit[x + k] < w)
            {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};


ll a[202020];
ll r[202020];
int solve()
{
    ll n, k;
    cin >> n >> k;
    set<ll> se;
    BIT bit(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= k;
    }
    r[0] = a[0];
    se.insert(r[0]);
    for (int i = 1; i < n; i++)
    {
        r[i] = r[i - 1] + a[i];
        se.insert(r[i]);
    }

    map<ll, ll> m;
    ll cnt = 1;
    for (auto t : se)
    {
        m[t] = cnt;
        cnt++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (r[i] >= 0)
            ans++;
        r[i] = m[r[i]];
    }
    // if (n == 1)
    // {
    //     cout << ans << endl;
    //     return 0;
    // }

    for (int i = 0; i < n; i++)
    {
        ans += bit.sum(r[i]);
        bit.add(r[i], 1);
    }
    cout << ans << endl;

    return 0;
}

int main()
{
    //cout.precision(10)
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}