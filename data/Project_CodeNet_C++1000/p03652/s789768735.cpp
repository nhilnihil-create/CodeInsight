typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
int main() {
    ll n,m;
    std::cin >> n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            a[i][j]--;
        }
    }
    
    ll ans = 400;
    
    vector<ll> now(n,0);
    
    ll rem = m;
    
    vector<bool> doo(m,true);
    
    while(rem>0){
        map<ll,ll> ma;
        for (int j = 0; j < n; j++) {
            ma[ a[j][now[j]] ]++;
        }
        
        ll tmp_max=0;
        
        
        for (auto e : ma) {
            tmp_max = max(tmp_max, e.second);
        }
        
        ans = min(ans, tmp_max);
        
        for (auto e : ma) {
            if(e.second == tmp_max){
                rem--;
                doo[e.first]=false;
            }
        }
        
        for (int i = 0; i < n; i++) {
            while(!doo[ a[i][now[i]] ] ){
                now[i]++;
                if(now[i]==m)break;
            }
        }
    }
    
    std::cout << ans << std::endl;
}