#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

int main(){
  ll n;
  cin>>n;
  ll logn=floor(log2(n));
  vector<ll> x(n);
  rep(i,n)cin>>x[i];
  ll l,q;
  cin>>l>>q;
  vector<vector<ll>> next(n,vector<ll>(logn+1));
  rep(i,n){
    next[i][0]=upper_bound(x.begin(), x.end(), x[i]+l)-1-x.begin();
  }
  rep(k,logn){
    rep(i,n){
      next[i][k+1]=next[next[i][k]][k];
    }
  }
  rep(i,q){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    if(a>b)swap(a,b);
    ll ans=0;
    ll now=a;
    for(int k=logn;k>=0;k--){
      if(next[now][k]<b){
        now=next[now][k];
        ans+=(1<<k);
      }
    }
    cout<<ans+1<<endl;
  }
}

