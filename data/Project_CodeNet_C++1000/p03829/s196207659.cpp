#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
void chmin(ll &x, ll y) { x = min(x, y); }
void chmax(ll &x, ll y) { x = max(x, y); }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<ll> v(n), d(n-1);
    rep(i, n) cin >> v[i];
    for(int i=0; i<n-1; i++) d[i] = v[i+1] - v[i];

    ll ans = 0;
    rep(i, d.size()){
        if(d[i]*a < b) ans += d[i]*a;
        else ans += b;
    }

    cout << ans << endl;
}