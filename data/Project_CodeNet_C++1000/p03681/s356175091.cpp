#include<iostream>
using namespace std;
using ll = long long;

ll func(ll x){
    if(x<=1) return 1;
    return x*func(x-1)%1000000007;
}

int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    if(n<m) swap(n,m);
    if(n==m) ans=func(n)*func(m)*2;
    else if(n-m<=1) ans=func(n)*func(m);
    ans%=1000000007;
    cout<<ans<<endl;
}