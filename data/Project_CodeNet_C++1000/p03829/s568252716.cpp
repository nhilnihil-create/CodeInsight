#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll x,nowx,ans=0;
    cin>>nowx;
    rep(i,n-1){
        cin>>x;
        if((x-nowx)*a<b) ans+=(x-nowx)*a;
        else ans+=b; 
        nowx=x;
    }
    cout<<ans<<endl;
    return 0;
}