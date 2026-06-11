#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

ll x[100010];

int main(){
    int n;
    ll a, b;
    cin >> n >> a >> b;
    rep(i, n) cin >> x[i];

    ll ans = 0;

    rep(i, n - 1){
        ll diff = x[i+1] - x[i];
        ans += min(diff * a, b);
    }

    cout << ans << endl;

    return 0;
}