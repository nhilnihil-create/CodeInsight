#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (ll i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool dp1[5005][5005];
bool dp2[5005][5005];

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    dp1[0][0] = true;
    rep(i, n) {
        rep(j, k+1) {
            dp1[i+1][j] = dp1[i][j];
            if (j-a[i]>=0) dp1[i+1][j] |= dp1[i][j-a[i]];
        }
    }
    dp2[n][0] = true;
    rrep(i, n) {
        rep(j, k+1) {
            dp2[i][j] = dp2[i+1][j];
            if (j-a[i]>=0) dp2[i][j] |= dp2[i+1][j-a[i]];
        }
    }
    int ans = 0;
    rep(i, n) {
        //debug(i);
        bool ok = false;
        vector<ll> v1;
        vector<ll> v2;
        rep(j, k+1) {
            if (dp1[i][j]) v1.push_back(j);
            if (dp2[i+1][j]) v2.push_back(j);
        }
        ll low = max(k-a[i], 0LL);
        for (ll e1: v1) {
            auto it = lower_bound(whole(v2), low-e1);
            if (it==v2.end()) continue;
            ll e2 = *it;
            if (e1+e2<k) {
                ok = true;
                break;
            }
        }
        if (!ok) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
