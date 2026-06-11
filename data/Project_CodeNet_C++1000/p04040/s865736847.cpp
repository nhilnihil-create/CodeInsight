#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define debug(...) cout << "[" << #__VA_ARGS__ << ": " << __VA_ARGS__ << "]\n"
#define rd() abs((int)rng())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int>pii;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n, m, a, b;
ll fac[maxn], inv[maxn];
ll pwr(ll a, ll pw)
{
    ll ret = 1;
    while(pw > 0)
    {
        if(pw & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        pw >>= 1;
    }
    return ret;
}
ll modinv(ll a)
{
    return pwr(a, mod - 2);
}
ll ways(int x, int y, int xx, int yy)
{
    return fac[xx - x + yy - y] * inv[xx - x] % mod * inv[yy - y] % mod;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    fac[0] = 1, inv[0] = 1;
    for(ll i = 1; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = modinv(fac[i]);
    }
    cin >> n >> m >> a >> b;
    a = n - a + 1;
    ll ans = ways(1, 1, n, m), sub = 0;
    for(int i = 1; i <= b; i++)
        sub = (sub + ways(1, 1, a - 1, i) * ways(a, i, n, m) % mod) % mod;
    cout << (ans - sub + mod) % mod << "\n";
    return 0;
}
