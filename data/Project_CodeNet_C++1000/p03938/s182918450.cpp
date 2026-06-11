#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
using ll=long long;
using namespace std;
ll p[22000],b[22000];
int main(){
  ll n,x=20010;
  cin>>n;
  ll y=n;
  rep(i,0,n)cin>>p[i];
  rep(i,0,n){cout<<x<<" ";x+=20010;}
  cout<<endl;
  b[p[0]]=500000000;
  rep(i,1,n+1){b[p[i]]=(p[i-1]-p[i])*20010+b[p[i-1]]+1;}
  rep(i,1,n+1)cout<<b[i]<<" ";
}