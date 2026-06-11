#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;


int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll ans = INF;
    for(int bit=0; bit<(1<<n); bit++){
        if(__builtin_popcount(bit) < k) continue;
        ll maxv = 0;
        ll sum = 0;
        rep(i, n){
            if(((bit>>i) & 1) && v[i] <= maxv){
                sum += (maxv - v[i] + 1);
                maxv++;
            }
            chmax(maxv, v[i]);
        }
        chmin(ans, sum);
    }

    cout << ans << endl;
}