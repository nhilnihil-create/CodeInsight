#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <queue>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for(int i=a, loop=b; i<=loop; ++i)
#define REV(i, a, b) for(int i=a, loop=b; i>=loop; --i)
#define mize(a, b) a = min(a, b)
#define maxi(a, b) a = max(a, b)
#define shl(k) ((k) << 1)
using namespace std;

const int N = 1e5+5;
int n, m, q, a[N], b[N];
char s[N], t[N];

int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> (s+1) >> (t+1);
    n = strlen(s+1); m = strlen(t+1);

    FOR(i, 1, n) a[i] = a[i-1] + (s[i]=='A'?+1:-1);
    FOR(i, 1, m) b[i] = b[i-1] + (t[i]=='A'?+1:-1);

    cin >> q; while (q--) {
        int u, v ,l ,r, x, y;
        cin >> u >> v >> l >> r;
        x = ((a[v]-a[u-1]) % 3 + 3) % 3;
        y = ((b[r]-b[l-1]) % 3 + 3) % 3;
        if (x == y) cout << "YES\n"; else cout << "NO\n";
    }
}
