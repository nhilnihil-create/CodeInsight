#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;
void Main()
{
    ll n;
    cin >> n;
    ll A, B;
    cin >> A >> B;
    vector<ll> X(n);
    rep(i, n) cin >> X[i];

    ll res = 0;
    rep(i, n - 1) {
        ll d = X[i+1] - X[i];
        ll c1 = d * A;
        ll c2 = B;
        res += min(c1, c2);
    }
    
    put(res);
}
signed main(){ Main();return 0;}