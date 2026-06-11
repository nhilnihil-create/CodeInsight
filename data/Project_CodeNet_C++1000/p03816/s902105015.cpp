#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        ll a;
        cin >> a;
        mp[a]++;
    }
    ll count=0;
    for(auto p:mp){
        if(p.second>=2) count+=p.second-1;
    }
    ll res=n-((count+1)/2)*2;
    cout << res << endl;
}
