#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    ll q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;

    ll a=q*4;
    ll b=q*2+h;
    ll c=h*2;

    ll ans=0;
    ll minv=min(min(a,b),min(c,s));
    
    if(n%2==1) ans=(n/2)*min(d,minv*2)+minv;
    else ans=(n/2)*min(d,minv*2);
    cout<<ans<<"\n";
    return 0;
}