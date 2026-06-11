#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll  n,a,b;
//vector<ll> s;
ll s[200000];
bool f(ll x){
    ll tmp=0;
    for(ll i=0;i<n;i++){
        if(s[i]-b*x>0)tmp+=((s[i]-b*x)-1)/(a-b)+1;//((s[i]-b*x)+a-b-1)/(a-b);//((s[i]-b*x)-1)/(a-b)+1;
    }
    return tmp<=x;
}    
signed main(void){
    // Your code here!
    cin>>n>>a>>b;
    //s.resize(n);
    for(ll i=0;i<n;i++){
        cin>>s[i];
    }
    ll ng=0;
    ll ok=1e9;
    while(ng+1<ok){
        ll mid=(ng+ok)/2;
        if(f(mid))ok=mid;
        else ng=mid;
    }
    cout<<ok<<endl;
}
