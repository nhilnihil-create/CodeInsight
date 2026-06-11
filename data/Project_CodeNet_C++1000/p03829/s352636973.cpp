#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    ll a, b;
    cin>>n>>a>>b;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    ll ans=0;
    rep(i, n-1){
        ans+=min(b, a*(v[i+1]-v[i]));
    }
    cout<<ans<<endl;
    return 0;
}