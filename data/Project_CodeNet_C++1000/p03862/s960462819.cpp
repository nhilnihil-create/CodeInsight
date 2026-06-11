#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000

int main(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){cin>>a[i];b[i]=a[i];}

    if(a[0]>x){a[0]=x;}
    for(ll i=0;i<n-1;i++){
        if(a[i]+a[i+1]>x){a[i+1]=x-a[i];}
    }

    ll ans=0;
    for(ll i=0;i<n;i++){
        ans+=abs(b[i]-a[i]);
    }

    cout<<ans<<endl;   
    return 0;
}