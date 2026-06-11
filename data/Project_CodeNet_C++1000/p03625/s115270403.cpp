#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin>>n;
    map<ll, int> mp;
    rep(i, n) {
        int a;
        cin>>a;
        mp[a]++;
    }
    vector<ll> v;
    for(auto p : mp){
        int c=p.second/2;
        rep(i, c) v.push_back(p.first);
    }
    if(v.empty()) {
        cout<<0<<endl;
        return 0;
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans=v[0]*v[1];
    cout<<ans<<endl;
    return 0;
}