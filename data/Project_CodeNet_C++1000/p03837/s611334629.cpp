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
    ll n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m), c(m);
    rep(i, m) cin >> a[i] >> b[i] >> c[i];

    // Warshall–Floyd 
    ll INF = 1e18;
    vector<vector<ll> > d(n, vector<ll>(n, INF));
    rep(i, m) {
        d[a[i] - 1][b[i] - 1] = c[i];
        d[b[i] - 1][a[i] - 1] = c[i];
    }
    rep (i, n) {
        rep (j, n) {
            if (i == j) d[i][j] = 0;
        }
    }
    rep(k, n) {
        rep (i, n) {
            rep (j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }        
    }
    
    ll res = 0;
    rep(i, m) {
        bool ok = false;
        rep(s, n) {
            if (d[s][a[i]-1] + c[i] == d[s][b[i]-1]) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            res++;
        }
    }

    put(res);
}
signed main(){ Main();return 0;}