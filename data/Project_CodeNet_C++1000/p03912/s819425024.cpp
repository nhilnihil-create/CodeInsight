#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> mod(m);
    for(i = 0;i < n;++i){
        ll x;
        cin >> x;
        mod.at(x%m).push_back(x);
    }
    ll ans = mod.at(0).size()/2;
    if(m%2 == 0){
        ans += mod.at(m/2).size()/2;
        for(i = 1;i < m/2;++i){
            if(mod.at(i).size() == mod.at(m-i).size()){
                ans += mod.at(i).size();
                continue;
            }
            ll ind;
            if(mod.at(i).size() < mod.at(m-i).size()) ind = m-i;
            else ind = i;
            ll plus = mod.at(m - ind).size();
            ll spare = mod.at(ind).size() - mod.at(m - ind).size();
            ll even = 0, odd = 0;
            sort(all(mod.at(ind)));
            ll tmp = mod.at(ind).at(0);
            ll cnt = 1;
            for(j = 1;j < mod.at(ind).size();++j){
                if(tmp == mod.at(ind).at(j)) ++cnt;
                else{
                    odd += cnt%2; even += cnt - cnt%2;
                    tmp = mod.at(ind).at(j);
                    cnt = 1;
                }
            }
            odd += cnt%2; even += cnt - cnt%2;
            ans += plus;
            if(spare >= even) ans += even/2;
            else{
                ans += (even - (plus - odd))/2;
            }
        }
    }else{
        for(i = 1;i <= (m-1)/2;++i){
            if(mod.at(i).size() == mod.at(m-i).size()){
                ans += mod.at(i).size();
                continue;
            }
            ll ind;
            if(mod.at(i).size() < mod.at(m-i).size()) ind = m-i;
            else ind = i;
            ll plus = mod.at(m - ind).size();
            ll spare = mod.at(ind).size() - mod.at(m - ind).size();
            ll even = 0, odd = 0;
            sort(all(mod.at(ind)));
            ll tmp = mod.at(ind).at(0);
            ll cnt = 1;
            for(j = 1;j < mod.at(ind).size();++j){
                if(tmp == mod.at(ind).at(j)) ++cnt;
                else{
                    odd += cnt%2; even += cnt - cnt%2;
                    tmp = mod.at(ind).at(j);
                    cnt = 1;
                }
            }
            odd += cnt%2; even += cnt - cnt%2;
            ans += plus;
            if(spare >= even) ans += even/2;
            else{
                ans += (even - (plus - odd))/2;
            }
        }
    }
    cout << ans << endl;

    return 0;
}