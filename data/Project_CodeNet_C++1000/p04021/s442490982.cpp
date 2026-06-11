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
    ll n;
    cin >> n;
    ll co = 0;
    vector<P> a;
    rep(i, n)
    {
        ll k;
        cin >> k;
        a.push_back(P(k, i));
    }
    sort(a.begin(), a.end());
    rep(i, n)
    {
        if (abs(a[i].second - i) % 2 == 1)
        {
            co++;
        }
    }
    cout << (co + 1) / 2 << endl;
}