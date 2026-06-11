#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll power(ll x,ll n){
    if(n==0) return 1;
    ll res=power(x*x%mod,n/2);
    if(n&1) res=res*x%mod;
    return res;
}

int main(){
  int n;
  cin>>n;
  int cnt[n];
  rep(i,0,n) cnt[i]=0;
  rep(i,0,n){
    int a;
    cin>>a;
    cnt[a]++;
  }
  if(n%2==0){
    bool p=true;
    rep(i,0,n){
      if(i%2==0){
        if(cnt[i]!=0) p=false;
      }
      else{
        if(cnt[i]!=2) p=false;
      }
    }
    if(p) cout<<power(2,n/2)<<endl;
    else cout<<0<<endl;
  }
  else{
    bool p=true;
    rep(i,0,n){
      if(i==0){
        if(cnt[i]!=1) p=false;
      }
      else{
        if(i%2==0){
          if(cnt[i]!=2) p=false;
        }
        else{
          if(cnt[i]!=0) p=false;
        }
      }
    }
    if(p) cout<<power(2,n/2)<<endl;
    else cout<<0<<endl;
  }
}