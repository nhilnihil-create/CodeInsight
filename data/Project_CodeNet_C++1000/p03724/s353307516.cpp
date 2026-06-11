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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(n);
    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        c[a[i]]++;
        c[b[i]]++;
    }
    string  ans = "YES";
    rep(i, n)
    {
        if (c[i]%2!=0) {
            ans="NO";
        }
    }
    cout << ans << endl;
}