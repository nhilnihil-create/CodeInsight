#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> x(n); rep(i,n) cin >> x[i];

    ll ans = 0;

    rep(i,n-1){
        ans += min(b,a*(x[i+1]-x[i]));
    }

    cout << ans << endl;
}