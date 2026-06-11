#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<n;i++)
using ll=long long;
using vl=vector<ll>;

int main(){
    ll n,k;cin >> n >>k;
    vl a(n),b(n);
    rep(i,n)cin >> a[i] >> b[i];
    ll res=0;
    rep(i,30){
        if((1LL<<i)&k){
            ll t=(1LL<<i);
            ll p=((k&~(1<<i))|(t-1));
            ll sum=0;
            rep(j,n){
                if(p==(p|a[j]))sum+=b[j];
            }
            res=max(res,sum);
        }
    }
    ll tot=0;
    rep(j,n){
        if(k==(k|a[j]))tot+=b[j];
    }
    cout << max(res,tot) <<endl;
}   
