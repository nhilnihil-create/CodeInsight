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
    ll n, x ;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = 0;
    rep(i, n - 1) {
        if (a[i] + a[i + 1] > x) {
            ll to = max(0LL, x - a[i]);
            sum += a[i + 1] - to;
            a[i + 1] = to;
            
            ll rem = a[i] + a[i + 1] - x;
            sum += rem;
            a[i] -= rem;
        }
    }

    put(sum);
}
signed main(){ Main();return 0;}