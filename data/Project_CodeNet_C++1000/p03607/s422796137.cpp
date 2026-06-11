#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;
using pll = pair<ll,ll>;
const ll INF64 = 1LL << 60;
const int INF = (1 << 29);

int main(){
    int n; cin >> n;
    map<ll,int> mp;
    rep(i,n){
        ll a; cin >> a;
        auto iti = mp.find(a);
        if(iti == mp.end()) mp[a] = 1;
        else{
            if(mp[a]==1) mp[a] = 0;
            else mp[a] = 1;
        }
    }

    int ans = 0;
    for(auto x: mp){
        ans += x.second;
    }
    cout << ans << endl;
}