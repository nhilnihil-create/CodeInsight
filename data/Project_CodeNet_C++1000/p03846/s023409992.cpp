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
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    vector<ll> C(n);
    rep(i, n) {
        C[A[i]]++;
    }

    if (n % 2 == 0){
        // 0, 2, 0, 2, ..
        rep(i, C.size()) {
            if (i % 2 == 0 && C[i] == 0) {
            }
            else if (i % 2 == 1 && C[i] == 2) {
            }
            else {
                put(0);
                return;
            }
        }
    }
    else {
        // 1, 0, 2, 0, 2, ...
        rep(i, C.size()) {
            if (i == 0 && C[i] == 1) {
            }
            else if (i % 2 == 0 && C[i] == 2) {
            }
            else if (i % 2 == 1 && C[i] == 0) {
            }
            else {
                put(0);
                return;
            }
        }
    }

    ll MOD = 1000000007;
    ll res = 1;      
    rep(i, n/2) res = (res * 2) % MOD;

    put(res);
}
signed main(){ Main();return 0;}