#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(ll i=0;i<(n);i++)

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g=gcd(a,b);
    return a/g*b;
}

int main(){
    ll n;
    cin>>n;
    vector<ll>t(n);
    rep(i,n)cin>>t[i];
    sort(t.begin(),t.end());
    ll ans=1;
    rep(i,n){
       ans=lcm(ans,t[i]);
        
    }
    printf("%lld",ans);
} 