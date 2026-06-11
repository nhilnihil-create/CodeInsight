#include <bits/stdc++.h> 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define cout(x) cout<<x<<endl
#define all(v) v.begin(), v.end()
using namespace std;
//型エイリアス
using vi = vector<int>;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
const ll inf = 1e18;
const int N = 2e5 + 10;

ll Manhattan(ll x1, ll y1, ll x2, ll y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(n); 
    rep(i,n) cin >> a[i] >> b[i];
    vector<ll> c(m),d(m);
    rep(i,m) cin >> c[i] >> d[i];

    vector<int> cp(n,0);
    rep(i,n){
        ll min_dist = 1e10;
        rep(j,m){
            ll dist = Manhattan(a[i],b[i],c[j],d[j]);
            if(dist<min_dist){
                min_dist = dist;
                cp[i] = j+1;
            }
        }
    }
    rep(i,n) cout(cp[i]);
    return 0;
}