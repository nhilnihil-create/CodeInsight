#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
const ll MAX = 1001001;
const ll MOD = 1000000007;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll j = -1;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n - 1)
    {
        if (a[i] + a[i + 1] >= k)
        {
            j = i;
        }
    }
    vector<ll> ans;
    if (j >= 0)
    {
        cout << "Possible" << endl;
        rep2(i, 1, j + 1)
        {
            ans.push_back(i);
        }
        for (ll i = n - 1; i > j; i--)
        {
            ans.push_back(i);
        }

        rep(i, n - 1)
        {
            cout << ans[i] << endl;
        }
    }
    else
    {
        cout << "Impossible" << endl;
    }
}