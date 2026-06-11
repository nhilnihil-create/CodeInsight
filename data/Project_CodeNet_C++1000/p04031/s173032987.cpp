#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ld avg = accumulate(all(a), 0) / (ld)n;
    ll res = 1e18;
    for (ll mean = (ll)avg; mean <= 1 + (ll)avg; mean++) {
        ll sum = 0;
        rep(i, n) {
            sum += (a[i] - mean) * (a[i] - mean);
        }
        res = min(res, sum);
    }

    put(res);
}
signed main(){ Main();return 0;}