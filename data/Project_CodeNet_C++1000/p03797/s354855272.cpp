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
    ll N,M;cin>>N>>M;
    ll ans;
    if(N==M/2) ans=N;
    else if(N>M/2) ans=M/2;
    else ans=N+(M-N*2)/4;

    cout<<ans<<endl;
}