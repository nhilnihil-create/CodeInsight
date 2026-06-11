#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    ll n;
    cin>>n;
    ll t[n],a[n];
    for(ll i=0;i<n;i++){
        cin>>t[i];
    }
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> h(n),h2(n);
    h[0]=t[0];
    for(ll i=1;i<n;i++){
        if(t[i]>t[i-1]){
            h[i]=t[i];
        }
    }
    
    h2[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            h2[i]=a[i];
        }
    }
    ll mn=0;
    for(int i=0;i<n;i++){
        
        mn=max(mn,h2[i]);
        if(t[i]<mn){
            cout<<0<<endl;
            return 0;
        }
    }
    mn=0;
    ll mod=1e9+7;
    for(int i=n-1;i>=0;i--){
        mn=max(mn,h[i]);
        if(a[i]<mn){
            //cerr<<mod<<endl;
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(h[i]&&h2[i]&&h[i]!=h2[i]){
            //cout<<mod<<mod<<endl;
            cout<<0<<endl;
            return 0;
        }
        if(h2[i]) h[i]=h2[i];
    }


    ll ans=1;

    for(ll i=0;i<n;i++){
        if(h[i]==0){
            ans*=min(a[i],t[i]);
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}
