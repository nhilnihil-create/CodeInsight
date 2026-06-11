#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]>t) ans+=t;
        else ans+=a[i+1]-a[i];
    }
    ans+=t;
    cout<<ans<<endl;
}