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

ll va[201][201];
ll vb[201][201];

void Main()
{
    ll n, Ma, Mb;
    cin >> n >> Ma >> Mb;

    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    ll INF = 1e18;
    rep(i, 201) rep(j, 201) {
        va[i][j] = INF;
        vb[i][j] = INF;
    }

    rep(pat, 1LL << (n/2)) {
        ll A = 0, B = 0, C = 0;
        rep(i, n/2) {
            if (pat & (1LL << i)) {
                A += a[i];
                B += b[i];
                C += c[i];
            }
        }
        va[A][B] = min(va[A][B], C);
    }    
    rep(pat, 1LL << (n-n/2)) {
        ll offset = n/2;
        ll A = 0, B = 0, C = 0;
        rep(i, n - n/2) {
            if (pat & (1LL << i)) {
                A += a[offset + i];
                B += b[offset + i];
                C += c[offset + i];
            }
        }
        vb[A][B] = min(vb[A][B], C);
    }

    ll res = INF;
    rep(a1, 201) {
        rep(a2, 201) {
            ll A = a1 + a2;
            if (A <= 0 || A % Ma != 0) {
                continue;
            }
            rep(b1, 201) {
                ll b2 = (A / Ma) * Mb - b1;
                if (0 <= b2 && b2 < 201) {
                    ll c1 = va[a1][b1];                    
                    ll c2 = vb[a2][b2];
                    res = min(res, c1 + c2);
                }
            }
        }
    }

    if (res == INF) {
        put(-1);
    }
    else {
        put(res);
    }
}
signed main(){ Main();return 0;}