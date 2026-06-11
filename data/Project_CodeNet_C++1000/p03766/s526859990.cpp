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

const int N = 1e6+5, mod = 1e9+7;
int n;
int64_t a[N], s[N], f[N];

int main()
{
    ios::sync_with_stdio(); cin.tie(0);

    cin >> n;
    s[0] = a[0] = 1;
    s[1] = a[1] = 2;
    f[0] = f[1] = 1;
    FOR(i, 2, n) {
        f[i] = s[i-2];
        a[i] = (a[i-1] + f[i]) % mod;
        s[i] = (s[i-1] + a[i-1]) % mod;
    }

    int64_t ans;
    if (n == 1) ans = 1; else {
        ans = (a[n-2]*(n-1)%mod*(n-1)%mod + f[n-1]*(n-1)%mod + f[n]) % mod;
        FOR(i, 1, n-1) ans = (ans + f[i-1]*i%mod) % mod;
    }
    cout << ans;
}
