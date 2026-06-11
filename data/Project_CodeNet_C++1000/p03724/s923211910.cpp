#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n,m;
    cin >> n >> m;
    map<ll,ll> mp;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }
    bool flag=true;
    for(auto p:mp){
        if(p.second%2==1) flag=false;
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}  
