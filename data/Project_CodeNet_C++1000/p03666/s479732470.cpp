#include "bits/stdc++.h"

#pragma GCC optimize(2)

using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define ins insert

#define pii pair<ll, ll>
#define ll long long
#define lb long double
#define ull unsigned long long

#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define m_p(i, j) make_pair(i, j)
#define mem(a, x) memset(a, x, sizeof(a))
#define fcout(i) cout << setprecision(i) << fixed
#define endl "\n"
#define mul(a, b, p) (1ll * (a) * (b) % p)

const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;

ll n;
ll a, b, c, d;
int main()
{
    while (scanf("%lld", &n) == 1)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        for (ll i = 0; i <= n - 1; i++)
        {
            if ((b - a) >= (i * c - (n - i - 1) * d) && (b - a) <= (i * d - (n - i - 1) * c))
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
