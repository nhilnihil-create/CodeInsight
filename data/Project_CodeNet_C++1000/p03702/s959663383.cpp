#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
ll n,a,b,h[200001];
ll ok,ng,mid;
int solve(int x){
    ll g[200001];
    rep(i,n) g[i]=h[i];
    rep(i,n) g[i]-=x*b;
    ll sum=0;
    rep(i,n) sum+=(g[i]+a-b-1)/(a-b)*(g[i]>0);
    if(x>=sum) return 1;
    else return 0;
}
int search(){
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    if(solve(mid)) ok=mid;
    else ng=mid;
  }
}
int main(){
    cin>>n>>a>>b;
    rep(i,n) cin>>h[i];
    ng=0,ok=1e9;
    search();
    cout<<ok;
}