#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll c[n];
    for(ll i=0;i<n;i++)cin>>c[i];
    ll ans=0;
    for(ll i=0;i<n-1;i++){
        ll diff=c[i+1]-c[i];
        if(diff*a>b)ans+=b;
        else ans+=diff*a;
    }
    cout<<ans<<endl;
}