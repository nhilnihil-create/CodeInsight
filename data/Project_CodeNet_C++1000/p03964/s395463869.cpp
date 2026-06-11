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

    vector<ll> T(n), A(n);
    rep(i, n) cin >> T[i] >> A[i];
    
    ll t = T[0], a = A[0];
    repi(i, n) {
        ll v = 1e18;

        ll v1 = (t + T[i] - 1) / T[i];
        ll t1 = T[i] * v1;
        ll a1 = A[i] * v1;
        if (t1 >= t && a1 >= a) {
            v = min(v, v1);
        }

        ll v2 = (a + A[i] - 1) / A[i];
        ll t2 = T[i] * v2;
        ll a2 = A[i] * v2;
        if (t2 >= t && a2 >= a) {
            v = min(v, v2);
        }

        t = T[i] * v;
        a = A[i] * v;
    }

    cout << t + a << endl;
}
signed main(){ Main();return 0;}