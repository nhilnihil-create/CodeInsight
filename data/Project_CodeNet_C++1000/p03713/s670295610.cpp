#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define ll long long

ll check(ll h,ll w){
    if(h%3==0)return 0;
    ll ans=1e9;
    for(ll i=1;i<h;i++){
        ll a=i*w,b=(h-i)*(w/2),c=(h-i)*(w-w/2);
        ll m=max(a,max(c,b))-min(a,min(c,b));
        ans=min(ans,m);
    }
    return min(h,ans);
}

int main(){
    ll h,w;
    cin>>h>>w;
    cout<<min(check(h,w),check(w,h));
}

//Persist for love.
