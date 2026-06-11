/*
 _    _    _______   _    _
| |  / /  |  _____| | |  / /
| | / /   | |       | | / /
| |/ /    | |_____  | |/ /
| |\ \    |  _____| | |\ \
| | \ \   | |       | | \ \
| |  \ \  | |_____  | |  \ \
|_|   \_\ |_______| |_|   \_\

*/
/*#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <assert.h>*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define right(x) x << 1 | 1
#define left(x) x << 1
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mkp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define y1 kekekek

const ll ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const ld eps = 1e-7;
const int N = 2e6 + 6;

ll n, m, cnt, sz[N], col[N];
bool u[N], bad[N];
vector < ll > g[N];

void dfs(ll v) {
    u[v] = 1;
    sz[cnt]++;
    for (auto to : g[v]) {
        if (!u[to]) {
            col[to] = col[v] ^ 1;
            dfs(to);
        }
        if (col[to] == col[v]) bad[cnt] = 1;
    }
}

int main() {
	ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    forn(i, 1, m) {
        ll x, y;
        cin >> x >> y;
        g[x].eb(y);
        g[y].eb(x);
    }

    forn(i, 1, n) {
        if (!u[i]) {
            ++cnt;
            dfs(i);
        }
    }

    ll ans = 1ll * n * n, sum = 0, c = 0, b = 1;
    forn(i, 1, cnt) {
        if (sz[i] == 1) continue;
        ans -= 1ll * sz[i] * sum * 2 + 1ll * sz[i] * sz[i];
        sum += sz[i];
        if (bad[i]) {
            ans += 1ll * 2 * (b - 1) + 1;
        }
        else {
            ans += 1ll * (b - c - 1) * 2 + 1ll * c * 4 + 2;
            ++c;
        }
        ++b;
    }

    cout << ans << "\n";

	return 0;
}
