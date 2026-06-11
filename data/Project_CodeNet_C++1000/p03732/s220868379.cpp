//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1e9 + 7;
void solve(){
    ll n, s;
    cin >> n >> s;
    ll ans = 0;
    unordered_map<ll, vi> a;
    vector<pair<ll, ll>> sz;
    for (ll i = 0; i < n; ++i) {
        ll w, v;
        cin >> w >> v;
        a[w].pb(v);
    }
    for (auto& p : a) {
        sort(rall(p.se));
        sz.pb({p.fi, p.se.size()});
    }
    ll sum0 = 0;
    for (ll i = 0; i <= sz[0].se; ++i) {

        if (i != 0) sum0 += a[sz[0].fi][i - 1];
        ll sum = i * sz[0].fi;

        if (sz.size() > 1) {
            ll sum1 = 0;

            for (ll j = 0; j <= sz[1].se; ++j) {
                if (j != 0) sum1 += a[sz[1].fi][j - 1];

                if (sz.size() > 2) {
                    ll sum2 = 0;

                    for (ll k = 0; k <= sz[2].se; ++k) {
                        if (k != 0) sum2 += a[sz[2].fi][k - 1];

                        if (sz.size() > 3) {
                            ll sum3 = 0;
                            for (ll l = 0; l <= sz[3].se; ++l) {
                                if (l != 0) sum3 += a[sz[3].fi][l - 1];
                                if (sum + j * sz[1].fi + k * sz[2].fi + l * sz[3].fi <= s) {
                                    ans = max(ans, sum1 + sum2 + sum3 + sum0); 
                                }
                            }
                        }

                        if (sum + j * sz[1].fi + k * sz[2].fi <= s) {
                            ans = max(ans, sum1 + sum2 + sum0); 
                        }
                    }
                }

                if (sum + j * sz[1].fi <= s) {
                    ans = max(ans, sum0 + sum1);
                }
            }
        }
        if (sum <= s) ans = max(ans, sum0);
    }
    cout << ans;
}
int main(){
    speed;
    ll t = 1;
    //cin >> t;
    for (ll i = 1; i <= t; ++i) {
        solve();
    }
}