#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;
 
int main() {
    ll N, W;
    cin >> N >> W;
 
    vec<vec<ll>> v(4,vec<ll>(1));
    ll w0;
    cin >> w0 >> v[0][0];
    rep(i, N-1){
        ll w,val;
        cin >> w >> val;
        v[w-w0].push_back(val);
    }
 
    rep(i,4){
        sort(all(v[i]),greater<ll>());
        v[i].insert(v[i].begin(),0);
        for(int j=1;j<v[i].size();++j){
            v[i][j] = v[i][j]+v[i][j-1];
        }
    }
 
    ll ans = 0;
    rep(i,v[0].size())rep(j,v[1].size())rep(k,v[2].size())rep(l,v[3].size()){
        ll count = w0*(i+j+k+l)+j+2*k+3*l;
        if(count > W) break;
        ans = max(ans,v[0][i]+v[1][j]+v[2][k]+v[3][l]);
    }
 
    cout << ans;
    return 0;
}