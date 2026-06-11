#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll int
#define ld long double
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;
ll n, m, x[N], y[N], vx[N], vy[N];
int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
ll sub(int a, int b){
    return (((a - b) % mod) + mod) % mod;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        vx[i] = x[i] - x[i - 1];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
        vy[i] = y[i] - y[i - 1];
    }
    ll w = 0, l = 0, ans = 0;
    for(int i = 1; i < n; i++)
        l = add(l, mul(mul(n - 1, n - i), vx[i]));
    for(int i = 1; i < n; i++)
        l = sub(l, mul(vx[i], mul(n - i, n - i - 1)));
    for(int i = 1; i < m; i++)
        w = add(w, mul(mul(m - 1, m - i), vy[i]));
    for(int i = 1; i < m; i++)
        w = sub(w, mul(vy[i], mul(m - i, m - i - 1)));
    ans = mul(l, w);
    cout << ans;
    return 0;
}
