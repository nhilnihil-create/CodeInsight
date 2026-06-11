#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io
    
    ll n, T;cin>>n>>T;
    ll t[n];
    rep(i,n) cin>>t[i];
    ll ans=0;
    rep(i,n-1){
        ans+=min(t[i+1]-t[i], T);
    }
    cout<<ans+T<<endl;

    return 0;
}