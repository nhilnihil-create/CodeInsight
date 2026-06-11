#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
typedef long long ll;
typedef vector<ll> vl;
#define rp(i, f, t) for (long long int i = f; i < t; i++)
#define pr(i, f, t) for (long long int i = t - 1; i >= f; i--)
#define ca(n, a) rp(ca_i, 0, n) cout << a[ca_i] << ((ca_i == n - 1) ? "\n" : " ")
#define za(n, a) rp(za_i, 0, n) a[za_i] = 0
#define be(a) a.begin(), a.end()
#define ce(a) cout << (a) << endl
int main()
{
    ll h, w;
    cin >> h >> w;
    ll n;
    cin >> n;
    ll a[n];
    rp(i, 0, n) cin >> a[i];
    vl aa;
    rp(i, 0, n)
    {
        rp(j, 0, a[i]) aa.push_back(i + 1);
    }
    ll ans[h][w];
    ll co = 0;
    rp(i, 0, h)
    {
        if (i % 2 == 0)
        {
            rp(j, 0, w)
            {
                cout << aa[co] << ((j == w - 1) ? "\n" : " ");
                co++;
            }
        }
        else
        {
            ll coco = co;
            rp(j, 0, w)
            {
                cout << aa[coco + w - j - 1] << ((j == w - 1) ? "\n" : " ");
                co++;
            }
        }
    }
}