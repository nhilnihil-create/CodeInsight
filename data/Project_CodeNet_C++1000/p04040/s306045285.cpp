#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll table[200001],table2[200001];
ll h,w,a,b;
ll mod=1e9+7;
ll f(ll x,ll y){
    if(y==1)return x;
    if(y%2==0)return (f(x,y/2)%mod*f(x,y/2)%mod)%mod;
    else return (f(x,y-1)%mod*x)%mod;
}
ll comb(ll x,ll y){
    x-=2,y--;
    if(x==0)return 1;
    if(y==0)return 1;
    ll ans=1;
    ans*=table[x-1];
    ans%=mod;
    ans*=table2[y-1];
    ans%=mod;
    ans*=table2[max(0LL,x-y-1)];
    ans%=mod;
    return ans;
}
int main(void){
    ll cnt=1;
    for(ll i=1;i<=200001;i++){
        cnt*=i;
        cnt%=mod;
        table[i-1]=cnt%mod;
        if(i<=200001){
            table2[i-1]=f(cnt,mod-2)%mod;
        }
    }
    //cout<<table[199998]<<endl;
    cin>>h>>w>>a>>b;
    ll ans=0;
    for(ll i=0;i<h-a;i++){
        ans+=comb(b+i+1,i+1)*comb(h-i+w-b,w-b);
        ans%=mod;
        //cout<<comb(b+i+1,i+1)<<comb(100009,3)<<endl;
    }
    cout<<ans<<endl;
}
