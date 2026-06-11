#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;

template <typename T>
void read(T &x)
{
    static char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar()) ;
    for (x = 0; isdigit(ch); ch = getchar())
        x = (x<<3)+(x<<1)+ch-'0';
}

const int N = 2e5+10, p = 1e9+7;

int h, w, a, b;
ll f[N], inv[N];

ll qpow(ll x, int k)
{
    ll ret = 1;
    while (k)
    {
        if (k&1) ret = (ret*x)%p;
        k >>= 1;
        x = (x*x)%p;
    }
    return ret;
}

void pre()
{
    f[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        f[i] = f[i-1]*i%p;
        inv[i] = qpow(f[i], p-2);
    }
}

int main()
{
    pre();
    read(h), read(w), read(a), read(b);
    ll ans = 0, t;
    for (int i = 0, j = b; i < h-a; ++i)
    {
        t = f[i+j-1]*inv[i]%p*inv[j-1]%p*
            f[w+h-2-i-j]%p*inv[h-1-i]%p*inv[w-1-j]%p;
        //printf("%d %d %d \n", i, j, t);
        ans = (ans+t)%p;
    }
    cout << ans << endl;
}
