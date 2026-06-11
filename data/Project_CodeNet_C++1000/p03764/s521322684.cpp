#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<ll> x(n);
    rep (i, n) {
        cin >> x[i];
    }

    vector<ll> y(m);
    rep (i, m) {
        cin >> y[i];
    }

    ll xsum = 0;
    rep (i, n-1) {
        ll j = i+1;
        xsum += (x[j]-x[i])%MOD*(i+1)%MOD*(n-j)%MOD;
        xsum %= MOD;
    }

    ll ysum = 0;
    rep (i, m-1) {
        ll j = i+1;
        ysum += (y[j]-y[i])%MOD*(i+1)%MOD*(m-j)%MOD;
        ysum %= MOD;
    }

    cout << xsum%MOD*ysum%MOD << endl;
    return 0;
}