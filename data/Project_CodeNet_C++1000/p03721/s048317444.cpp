#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P  pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    ll ans = 0;
    for(auto m: mp) {
        if (m.second>=k) {
            ans = m.first;
            break;
        }
        else {
            k -= m.second;
        }
    }
    
    cout << ans << endl;
    return 0;
}
