#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll mod=1000000007;

int main(){
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> t(n);
    for(ll i=0;i<n;++i){
        cin>>t[i];
    }
    sort(t.begin(),t.end());
    
    ll ans=0,cnt=0,mi=0;
    for(ll i=0;i<n;++i){
        cnt++;
        if(cnt>c||t[mi]+k<t[i]){
            cnt=1;
            ans++;
            mi=i;
        }
    }
    if(cnt>0){
        ans++;
    }
    cout<<ans;
    return 0;
}