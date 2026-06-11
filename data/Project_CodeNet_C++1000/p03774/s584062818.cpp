#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll INF=LLONG_MAX;

int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<ll,ll>> stu(n);
  vector<pair<ll,ll>> check(m);
  rep(i,n){
    ll a,b; cin>>a>>b;
    stu[i]=make_pair(a,b);
  }
  rep(i,m){
    ll c,d; cin>>c>>d;
    check[i]=make_pair(c,d);
  }
  for(auto x : stu){
    ll dist=INF;
    int tmp=0;
    int ans;
    for(auto y : check){
      tmp++;
      ll now_dist=abs(x.first-y.first)+abs(x.second-y.second);
      if(now_dist<dist) {ans=tmp; dist=now_dist;}
    }
    cout<<ans<<endl;
  }
}
