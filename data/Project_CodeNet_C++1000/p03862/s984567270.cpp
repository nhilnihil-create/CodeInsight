#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n,x;cin>>n>>x;
    ll e,ans;
    ans=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-1;i++){
        e=max((ll)0,(a[i]+a[i+1])-x);
        ans+=e;
        a[i+1]=max((ll)0,a[i+1]-e);
    }
    cout<<ans<<endl;
}
