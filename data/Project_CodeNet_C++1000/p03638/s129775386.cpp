#include <bits/stdc++.h>
// #include <atcoder/all>
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
// using namespace atcoder;
void Main()
{
    ll H, W, n;
    cin >> H >> W >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    vector<ll> v;
    rep(i, n) {
        rep(j, a[i]) v.push_back(i + 1);
    }

    vector<vector<ll> > res(H, vector<ll>(W));
    ll cnt = 0;
    rep(i, H) {
        rep(j, W) {
            ll x = j;
            if (i % 2 == 1) {
                x = W - 1 - j;
            }
            res[i][x] = v[cnt];
            cnt++;
        }
    }

    rep(j, H) {
        rep(i, res[j].size()) cout << res[j][i] << (i == res[j].size() - 1 ? "" : " ");
        cout << endl;
    }

}
signed main(){ Main();return 0;}