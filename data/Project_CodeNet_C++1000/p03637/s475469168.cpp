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
    ll n;
    cin >> n;
    ll a[n];
    rp(i, 0, n) cin >> a[i];
    ll so[3];
    za(3, so);
    rp(i, 0, n)
    {
        if (a[i] % 4 == 0)
        {
            so[2]++;
        }
        else
        {
            if (a[i] % 2 == 0)
            {
                so[1]++;
            }
            else
            {
                so[0]++;
            }
        }
    }
    //ca(3, so);
    if (so[1] == 0)
    {
        if (so[0] - 1 <= so[2])
        {
            ce("Yes");
        }
        else
        {
            ce("No");
        }
    }
    else
    {
        if (so[0] <= so[2])
        {
            ce("Yes");
        }
        else
        {
            ce("No");
        }
    }
}