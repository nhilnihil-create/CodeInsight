#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7, Nmax = 2005;
typedef long long ll;

namespace
{
    void inm_to(int &x, int y) { x = (ll) x * y % Mod; }
    int inm(int x, int y) { return (ll) x * y % Mod; }
    int inm(int x, int y, int z) { return (ll) x * y % Mod * z % Mod; }
    void add_to(int &x, int y) { x+=y; if(x>=Mod) x-=Mod; }
    int add(int x, int y) { x+=y; return x<Mod ? x : x-Mod; }

    int power(int a, int b)
    {
        int ans = 1;
        while(b)
        {
            if(b&1) inm_to(ans, a);
            inm_to(a, a); b >>= 1;
        }
        return ans;
    }
}

int N, K;
int fact[2*Nmax*Nmax], ifact[2*Nmax*Nmax], dp[Nmax][Nmax];

int comb(int n, int k)
{
    return inm(fact[n], ifact[k], ifact[n-k]);
}

int aranj(int n, int m)
{
    /// comb(n+m, n)
    return comb(n+m, n);
}

void prec(int lim)
{
    int i;
    fact[0] = ifact[0] = 1;

    for(i=1; i<=lim; ++i) fact[i] = inm(fact[i-1], i);
    ifact[lim] = power(fact[lim], Mod-2);
    for(i=lim-1; i; --i) ifact[i] = inm(ifact[i+1], i+1);
}

int main()
{
   // freopen("input", "r", stdin);
   // freopen("output", "w", stdout);
    cin.sync_with_stdio(false);

    int i, j;
    cin >> N >> K;

    if(K == 1)
    {
        cout << 1 << '\n';
        return 0;
    }

    prec(2 * N * K);

    dp[0][0] = 1;

    for(i=0; i<=N; ++i)
        for(j=0; i+j<=N; ++j)
            if(i + j)
            {
                if(j) dp[i][j] = inm(dp[i][j-1], i+j, aranj(K-2, i * K + (j-1) * (K-1)));
                if(i) add_to(dp[i][j], dp[i-1][j+1]);
            }

    cout << dp[N][0] << '\n';

    return 0;
}
