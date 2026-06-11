#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
int main() {
    ll n,c,k;cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    sort(t.begin(),t.end());
    ll lim=0;
    ll count=0;
    ll fst=t[0];
    t.push_back(100000000000);
    for(ll i=0;i<n;i++){
        lim++;
        if(lim==c || t[i+1]-fst>k){
            lim=0;
            fst=t[i+1];
            count++;
        }
    }
    if(lim!=0) count++;
    cout<<count<<endl;
}