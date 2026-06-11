#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


ll a[100010];

int main(){
    ll n, k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    ll g = a[0];
    ll mx = a[0];
    rep(i, n-1){
        g = __gcd(g, a[i+1]);
        mx = max(mx, a[i]);
    }

    if (k%g == 0 && k <= mx) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}
