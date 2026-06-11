#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;
vector<pair<ll, ll>> v(100001 + 1);
 
int main(){
    ll n, m; cin >> n >> m;
    v[1].second = 1;
    for(ll i = 2; i <= n; ++i){
        v[i].first = 1;
    }
    for(ll i = 0; i < m; ++i){
        ll x, y; cin >> x >> y;
        if(v[x].first > 0){
            v[x].first--;
            if(v[y].second == 0 && v[x].second == 1){
                v[y].second++;
            }else{
                v[y].first++;
            }
        }else{
            v[x].second--;
            if(v[y].second == 0){
                v[y].second++;
            }else{
                v[y].first++;
            }
        }
    }
    ll ans = 0;
    for(auto x:v){
        //cout << x.first << " " << x.second << endl;
        if(x.second == 1) ans++;
    }
    cout << ans;
    return 0;
}
