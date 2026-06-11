#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); ++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
using ll = long long;

int main(){
  ll n,a,b;
  cin>>n>>a>>b;
  vector<ll>h(n);
  rep(i,n)cin>>h[i];
  ll d=a-b;
  auto judge=[&](ll mid){
    vector<ll>w=h;
    rep(i,n){
      w[i]-=b*mid;
    }
    ll cnt=0;
    rep(i,n){
      if(w[i]>0){
        cnt+=(w[i]+d-1)/d;
      }
    }
    if(cnt>mid)return 0;
    else return 1;
  };
  auto bs=[&](){
    ll l=-1,r=INF;
    while(r-l>1){
      ll mid=(l+r)/2;
      if(judge(mid)){
        r=mid;
      }
      else{
        l=mid;
      }
    }
    return r;
  };
  cout<<bs()<<endl;
  return(0);
}
