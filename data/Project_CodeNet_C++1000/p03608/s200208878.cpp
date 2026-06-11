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


ll cost[305][305];

void warshall_floyd(ll n){
    rep(k, n){
        rep(i, n){
            rep(j, n) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
    }
}

int main(){
    ll n, m, r;
    cin >> n >> m >> r;
    vector<ll> route;
    rep(i, r) {
        ll p;
        cin >> p;
        p--;
        route.push_back(p);
    }
    sort(route.begin(), route.end());

    rep(i, 305) rep(j, 305) cost[i][j] = LINF;
    // rep(i, 305) cost[i][i] = 0;

    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    warshall_floyd(n);

    ll ans = LINF;
    
    do {
        // rep(j, r) cout << route[j] << " ";
        // cout << endl;
        ll tmp = 0;
        rep(j, r - 1){
            tmp += cost[route[j]][route[j+1]];
        }
        ans = min(ans, tmp);
    } while(next_permutation(route.begin(), route.end()));

    cout << ans << endl;

    return 0;
}