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
    ll n, T;
    cin >> n >> T;

    vector<ll> t(n);
    rep(i, n) cin >> t[i];
    
    ll end = 0;
    ll sum = 0;
    rep(i, n) {
        sum += T;
        sum -= max(0LL, end - t[i]);
        end = t[i] + T;
    }

    put(sum);
}
signed main(){ Main();return 0;}