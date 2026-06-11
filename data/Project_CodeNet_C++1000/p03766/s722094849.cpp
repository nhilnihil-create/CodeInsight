// Crt. 2020-01-08  16:06:51
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1000006
using namespace std;
const int Mod = 1e9 + 7;

inline void inc(int &x, int y) {
    x += y; if (x >= Mod) x -= Mod;
}

inline int MOD(int x) {
    return x >= Mod ? x - Mod : x;
}

int n, f[N], sum[N];

int main(){
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n;
    f[0] = sum[0] = f[1] = 1, sum[1] = 2;
    for (int i = 2; i <= n; ++i)
        f[i] = MOD(sum[i - 1] + Mod - f[i - 2]),
        sum[i] = MOD(sum[i - 1] + f[i]);

    int ans = 0;

    for (int i = 0; i <= n - 2; ++i)
        inc(ans, 1ll * f[i] * (n - 1) % Mod * (n - 1) % Mod);

    //cout <<"!"<< ans << endl;

    for (int i = 0; i <= n - 1; ++i)
        inc(ans, 1ll * f[i] * min(n - 1, i + 1) % Mod);

    //cout << "@"<<ans<<endl;

    //inc(ans, 1ll * f[n - 1] * (n - 1) % Mod);

    //cout <<"#"<< ans << endl;

    inc(ans, f[n]);

    cout << ans << endl;

	return 0;
}