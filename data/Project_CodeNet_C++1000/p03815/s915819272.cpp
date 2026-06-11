#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<deque>
using namespace std;
#define rep(i,x,n) for(int i=x;i<n;i++)
using ll=long long;

int n;
string s;

ll gcl(ll x,ll y){
    if(x<y) swap(x,y);
    while(y>0){
        ll t=x%y;
        x=y;
        y=t;
    }
    return x;
}

ll fac(int n){
    if(n==0||n==1) return 1;
    return n*fac(n-1);
}

int main(){
    ll x;cin>>x;
    ll ans=(x+10)/11*2;
    if(ans/2*11-5>=x) ans--;
    cout<<ans<<endl;
}