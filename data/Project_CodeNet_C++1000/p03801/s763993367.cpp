#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n;
    cin>>n;
    pair<ll,ll> p[n];
    for(ll i=0;i<n;i++){
        ll a;
        cin>>a;
        p[i] = make_pair(a,-i);
    }
    sort(p,p+n,greater<pair<ll,ll>>());
    ll ans[n]={};
    ll ind = -1e9;
    ll cnt = 0;
    for(ll i=0;i<n;){
        ll a = p[i].first;
        while(i<n && a==p[i].first){
            cnt++;
            ind = max(ind,p[i].second);
            i++;
        }
        if(i<n) ans[-ind] += cnt * (a-p[i].first);
        else ans[-ind] += cnt*a;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }


    
}