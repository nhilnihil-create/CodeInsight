#include<bits/stdc++.h>

using namespace std;

typedef long long   ll;

const int   N   = 2e3 + 1;
const ll    mod = 1e9 + 7;

void add(int &a,int b)  {
    a += b;
    if(a >= mod)a -= mod;
    if(a < 0)   a += mod;
}

ll  qpow(ll a,int exp)  {
    ll ans = 1;
    while(exp)  {
        if(exp & 1) ans = ans * a % mod;
        a = a * a % mod;  exp >>= 1;
    }
    return ans;
}

ll  Fac[N * N];
ll  Inv[N * N];

int Ckn(int n,int k)    {
    if(n < k || n < 0 || k < 0) return 0;
    ll  res = Inv[k] * Inv[n - k] % mod;
        res = Fac[n] * res % mod;
    return (int)res;
}

int f[N][N];

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, K;   cin >> n >> K;

    if(K < 2)   return puts("1"),0;

    Fac[0] = 1;

    for(int i = 1 ; i <= n * K ; ++i)
        Fac[i] = 1ll * Fac[i - 1] * i % mod;

    Inv[n * K] = qpow(Fac[n * K],mod - 2);
    for(int i = n * K - 1 ; ~i ; --i)
        Inv[i] = 1ll * Inv[i + 1] * (i + 1) % mod;

    f[0][0] = 1;

    for(int i = 1 ; i <= n ; ++i)
        for(int j = 0 ; j <= i ; ++j)   {
            if(i)   add(f[i][j],f[i - 1][j]);
            if(j)   add(f[i][j],1ll * f[i][j - 1] * Ckn(n * K - i - (j - 1) * (K - 1) - 1,K - 2) % mod);
        }

    cout << 1ll * f[n][n] * Fac[n] % mod << endl;
}